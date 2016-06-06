#include <windows.h>
#include <stdint.h>

void os_sleep(long ms) {
  Sleep(ms);
}

int64_t os_get_pid() {
  return (int64_t)GetCurrentProcessId();
}

int os_get_random() {
  return (GetTickCount()%99999) + os_get_pid();
}

bool os_proc_is_alive(int64_t pid) {

  HANDLE proc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
  if (proc == NULL)
    return false;
  CloseHandle(proc);

  return true;
}

int64_t os_exec_path(char* filename) {
  /*qint64 pid;
  QProcess::startDetached(filename, QStringList(), ".", &pid);
  return pid;*/
  //TODO
  return 0;
}

void os_trap_setup() {
  //TODO
  return;
}

