#ifndef _STDIO_H
#define _STDIO_H
#include <stdio.h>
#endif

#ifndef _STRING_H
#define _STRING_H
#include <string.h>
#endif

#ifndef _SYS
#define _SYS

#ifndef _TYPES_H
#define _TYPES_H
#include <sys/types.h>
#endif

#ifndef _DIR_H
#define _DIR_H
#include <sys/dir.h>
#endif

#ifndef _PARAM_H
#define _PARAM_H
#include <sys/param.h>
#endif

#endif

namespace so_eafit 
{

  bool inside_is_a_process_dir(struct direct *element)
  {
    if( strcmp( element -> d_name, ".") == 0 or strcmp( element -> d_name, "..") == 0 or atoi( element -> d_name) <= 0)
      return false;
    return true;
      
  }
  int *GetProcessList(int *nroProcesos)
  {
    char * proc_path = "/proc/";
    struct direct **procs;
    if(getwd(proc_path) == NULL)
      {
	perror("Error getting the following path ");
	perror(proc_path);
	return NULL;
      }
    (* nroProcesos) = scandir(proc_path, &procs, inside_is_a_process_dir, NULL);
  }
  float CpuUsage()
  {
  }
}
