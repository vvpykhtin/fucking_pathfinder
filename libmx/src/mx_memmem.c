#include "libmx.h"
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
  size_t a  = 0;
  while(a < big_len)
    {
      if(((char *)big)[a] == ((char *)little)[0])
        {
          size_t i = 0;
          while(((char *)big)[a + i] == ((char *)little)[i])
            i++;
          if(i == little_len)
            return &((char *)big)[a];
        }
      a++;
    }
  return NULL;
}
