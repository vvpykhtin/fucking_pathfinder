#include "libmx.h"

int isdigits(char *c)
{
  int i = 0;
  while(c[i] != '\0')
    {
      if(c[i]<48 || c[i] >58)
	return 0;
      i++;
    }
  return 1;
}
