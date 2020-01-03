#include"libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
  int i = 0;
  while(i < len)
    {
      if(src[i] == '\0')
	{
	  while(i < len)
	    {
	      dst[i] = '\0';
	      i++;
	    }
	}
      else
	{
	  dst[i] = src[i];
	  i++;
	}
    }
  dst[i] = '\0';
  return (char *)dst;
}

