#include "libmx.h"

char *mx_strnew(const int size)
{
  char * res = malloc(size + 1 * sizeof(char));
  if(size < 0) return NULL; 
  for(int i = 0; i <= size ; i++)
    res[i] = '\0';
  return res;
}
