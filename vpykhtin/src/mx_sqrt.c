#include "libmx.h"
int mx_sqrt(int x)
{
  int result = 1;
  while(result <= x / 2)
    {
      if(result * result == x)
	return result;
      result++;
    }
  return 0;
}

