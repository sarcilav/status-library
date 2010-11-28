#include <iostream>
#include "libWin.h"

using namespace std;
int main()
{
  float cpu;
  cpu = GetCpuUsage();
  cout << cpu << endl;
  cout << "hola";
  return 0;
   }
