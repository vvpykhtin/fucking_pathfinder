#include "libmx.h"
void *mx_memmove(void *dst, const void *src, size_t len)
{
  for(size_t i = 0; i < len;i++)
    {
      ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
    }
  return dst;
}
