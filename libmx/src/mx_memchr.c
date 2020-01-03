#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
  size_t i = 0;
  while(i < n)
    {
      if(((unsigned char *)s)[i] == c)
	return &((unsigned char *)s)[i];
      i++;
    }
return NULL;
}
