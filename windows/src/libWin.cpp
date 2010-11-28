#include "libWin.h"
#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <winbase.h>
#include <psapi.h>

    
        
          DLLIMPORT int *GetProcessList(int *numProc){
            DWORD *procesos = new DWORD[1024];
            DWORD bites;
            EnumProcesses(procesos, DWORD(1024), &bites);
            *numProc = (int)(bites/sizeof(DWORD));
            
        //Casteo de DWORD a un int
        int *result = new int[*numProc];
        for(int i = 0; i < *numProc; ++i)
            result[i] = (int)procesos[i];
            
        return result;
    }
    
    DLLIMPORT float GetCpuUsage(){
		static ULARGE_INTEGER idleActual, kernelActual, userActual;
        FILETIME idle, kernel, user;
        GetSystemTimes(&idle, &kernel, &user);

       
        ULARGE_INTEGER userTime, kernelTime, idleTime;
        ULONGLONG longUser, longKernel, longIdle;
        userTime.LowPart = user.dwLowDateTime;
        userTime.HighPart = user.dwHighDateTime;                        //Casteos
        kernelTime.LowPart = kernel.dwLowDateTime;
        kernelTime.HighPart = kernel.dwHighDateTime;
        idleTime.LowPart = idle.dwLowDateTime;
        idleTime.HighPart = idle.dwHighDateTime;
        
        longUser = userTime.QuadPart-userActual.QuadPart;
        longKernel = kernelTime.QuadPart-kernelActual.QuadPart;
        longIdle = idleTime.QuadPart-idleActual.QuadPart;
        
        idleActual = idleTime, userActual = userTime, kernelActual = kernelTime;

        return float((float)(longUser+longKernel)/(float)(longUser+longKernel+longIdle));
    }


BOOL APIENTRY DllMain (HINSTANCE instanciaLib /* Library instance handle. */ ,
                       DWORD called /* Reason this function is being called. */ ,
                       LPVOID reserved /* Not used. */ )
{
    switch (called)
    {
      case DLL_PROCESS_ATTACH:
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}

