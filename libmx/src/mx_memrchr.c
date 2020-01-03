#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
  size_t i =  mx_strlen(s);
  size_t r = 0;
  while(r <= n)
    {
      if(((unsigned char *)s)[i] == c)
	return &((unsigned char *)s)[i];
      i--; r++;
    }
  return NULL;
}
