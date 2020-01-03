#include "libmx.h"
int mx_get_substr_index(const char *str, const char *sub)
{
  int i = 0;
  if(!str || !sub) return -2;
  while(*str)
    {
      if(*str == *sub)
		{
			int s = 0;
			const char * p = str;
	  	while(*p == sub[s])
	    {
	       	s++;
			p++;
		
	    }
	  if(sub[s] == '\0') return i;
	  
	}
      str++; i++;
    }
  return -1;
}
