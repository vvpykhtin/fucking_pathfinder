#include"libmx.h"

void mx_str_reverse(char *s)
{
if(s) {
  int len = mx_strlen(s);
  int i = 0;
  while(i < mx_strlen(s) / 2)
    {
      mx_swap_char(&s[i], &s[len - 1]);
	i++; len--;
    }
}
}
