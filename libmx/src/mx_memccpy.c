#include"libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
  size_t i = 0;
  while(i < n)
    {
      if( ((unsigned char *)src) [i] == c )
	{
	  ((unsigned char *)dst)[i]  = ((unsigned char *)src)[i];
	  return dst; 
	}
      ((unsigned char *)dst)[i]  = ((unsigned char *)src)[i];
      i++;
    }
  return dst;
}
