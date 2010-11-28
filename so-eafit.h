#ifndef _SO_EAFITH
#define _SO_EAFITH
#ifdef _WIN32
  #if BUILDING_DLL
    #define DLLIMPORT __declspec (dllexport)
  #else
    #define DLLIMPORT __declspec (dllimport)
  #endif
  #include <windows.h>
#else
  #define DLLIMPORT extern 
  #include <unistd.h>
#endif

DLLIMPORT int *GetProcessList(int *nroProcesos){
  return GetProcessList(nroProcesos);
}
DLLIMPORT float CpuUsage(){
  return CpuUsage();
}
#endif
// int main()
// {
//   int n;
//   int *ans = GetProcessList(&n);
//   for(int i = 0; i < n; ++i)
//     printf("%d\n", ans[i]);
//   CpuUsage();
//   sleep(10);
//   printf("The usage of the cpu is %f\n", CpuUsage());
//   return 0;
// }
