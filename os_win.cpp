#include <windows.h>
#include <stdint.h>

int32_t CREATE_PROC_FLAGS = CREATE_BREAKAWAY_FROM_JOB | 
                            CREATE_NO_WINDOW | 
                            CREATE_NEW_PROCESS_GROUP  | 
                            DETACHED_PROCESS ;

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
  PROCESS_INFORMATION proc_info;
  CreateProcess(filename, NULL, NULL, NULL, FALSE, CREATE_PROC_FLAGS, NULL, NULL, GetStartupInfo(), &proc_info);
  int64_t pid = proc_info->dwProcessid; 
  CloseHandle(proc_info);
  return pid;
}

void os_trap_setup() {
  //TODO
  return;
}

