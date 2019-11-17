#include "libmx.h"
int abcd(char c)
{
  if(c == 'A' || c == 'a') return 10;
  if(c == 'B' || c == 'b') return 11;
  if(c == 'C' || c == 'c') return 12;
  if(c == 'D' || c == 'd') return 13;
  if(c == 'E' || c == 'e') return 14;
  if(c == 'F' || c == 'f') return 15;
  return 0;
}

unsigned long  pl(double n, int pow)
{
  if(pow >=0)
    {
      unsigned long result = 1;
      for(int i = 0; i < pow; i++)
	result *= n;
      return result;
    }
  return 0;
}
unsigned long mx_hex_to_nbr(const char *hex)
{
if(!hex) return 0;
  unsigned long res = 0;
  int len = mx_strlen(hex) - 1;
  for(int i = 0; i < mx_strlen(hex); i++)
    {
      if((hex[i] > 64 && hex[i] < 71) || (hex[i] > 96 && hex[i] < 103) ||(hex[i] > 47 && hex[i] < 58)) {
      if(i == mx_strlen(hex) - 1)
	{
	  if(hex[i] > 47 && hex[i] < 58) {
	  res+= hex[i] - 48;
	  return res;
	  }
	  else return res+= abcd(hex[i]);
	}
       if(hex[i] > 47 && hex[i] < 58)
	{
	  res+=(hex[i] - 48) * pl(16,len);;
	  len--;
	}
       if((hex[i] > 64 && hex[i] < 71) || (hex[i] > 96 && hex[i] < 103))
	{
	  res+=abcd(hex[i]) * pl(16,len);
	  len--;
	}
    }
      else return 0;
    }
  return res;
}

