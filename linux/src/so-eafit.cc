#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>


int inside_is_a_process_dir(const struct direct *element)
{
  if(atoi( element -> d_name) > 0)
    return true;
  else 
    return false;
}
int *GetProcessList(int *nroProcesos)
{
  const char * proc_path = "/proc/";
  struct direct **procs;
  if(chdir(proc_path) != 0)
    {
      perror("Error getting the following path ");
      perror(proc_path);
      return NULL;
    }
  int n;
  n = (* nroProcesos) = scandir(proc_path, &procs, inside_is_a_process_dir, NULL);
  int *ans = new int[n] ;
  for(int i = 0; i < n ; ++i)
    ans[i] = atoi(procs[i] -> d_name);
  return ans;
}
float CpuUsage()
{
  static int user = 0 , nice = 0, sys = 0, idle = 0;
  int a_user, a_nice, a_sys, a_idle, du, dn, ds, di;
  int total = 0;
  freopen("/proc/stat", "r", stdin);
  scanf("cpu %d %d %d %d", &a_user, &a_nice, &a_sys, &a_idle);
  fclose(stdin);
  du = a_user - user;
  dn = a_nice - nice;
  ds = a_sys - sys;
  di = a_idle - idle;
  total += du + dn + ds + di;
  if(total == 0)
    return -1;
  user = a_user, nice = a_nice, sys = a_sys, idle = a_idle;
  float usage = du + dn + ds;
  return usage / (float) total;
}


int main()
{
  int n;
  int *ans = GetProcessList(&n);
  for(int i = 0; i < n; ++i)
    printf("%d\n", ans[i]);
  CpuUsage();
  sleep(10);
  printf("The usage of the cpu is %f\n", CpuUsage());
  return 0;
}
