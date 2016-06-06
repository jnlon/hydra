#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

#include <iostream>
#include <QtCore/QStringList>
#include <QtCore/QProcess>

#include "main.h"

QStringList NO_ARGS;

void os_sleep(long ms) {
  usleep(ms*1000);
}

int os_get_random() {
  return getpid() + clock();
}


int64_t os_get_pid() {
  return (int64_t)getpid();
}

bool os_proc_is_alive(long pid) {

  kill(pid, 0);
  if (errno == ESRCH) 
  {
    errno = 0;
    return false;
  }

  return true;
}

void spawn_wrapper(int i) {
  spawn_two_more();
}

int64_t os_exec_path(std::wstring filename) {
  std::cout << "filename: " << filename << std::endl;
  qint64 pid;
  int ret = QProcess::startDetached(filename, NO_ARGS, ".", &pid);
  std::cout << "ret: " << ret << std::endl;
  return pid;
}

void os_trap_setup() {
  signal(SIGTERM, spawn_wrapper);
  signal(SIGINT, spawn_wrapper);
  signal(SIGQUIT, spawn_wrapper);
  signal(SIGKILL, spawn_wrapper);
  signal(SIGHUP, spawn_wrapper);
  return;
}
