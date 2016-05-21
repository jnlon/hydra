#include <windows.h>
#include <stdint.h>

void os_sleep(long ms) {
  Sleep(ms);
}

int os_get_random() {
  return (GetTickCount()%99999) + std::time(NULL);
}

int64_t os_get_pid() {
  return (int64_t)GetCurrentProcessId();
}

bool os_proc_is_alive(long pid) {

  HANDLE proc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
  if (proc == NULL)
    return false;
  CloseHandle(proc);

  return true;
}

void os_trap_setup() {
  //TODO
  return;
}

