#include <so-eafit.h>
#include <stdio.h>
int main()
{
  int i,n;
  int *a = GetProcessList(&n);
  for( i = 0; i < n ; ++i)
    {
      printf("%d\n", a[i]);
    }
  printf("%f\n", CpuUsage());
  return 0;
}
