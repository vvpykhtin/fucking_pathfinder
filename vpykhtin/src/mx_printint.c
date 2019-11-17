#include "libmx.h"

void mx_printint(int n)
{
  int count = 1;
  long int nn = n;
  long int n1 = n;
  if(n1 < 0)
    {
      mx_printchar('-');
      n1 *= -1;
    }
  while(nn >= 10 || nn <= -10)
    {
      nn /=10;
      count *= 10;
    }
  while(count >= 1)
    {
      mx_printchar(n1 / count + 48);
      n1 %= count;
      count /= 10;
    }
}
