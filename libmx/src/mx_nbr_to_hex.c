#include"libmx.h"
char hex(int a)
{
 if(a >= 0  && a < 10)
   return a + 48;
 else
   return a + 87;
}
    
    
char *mx_nbr_to_hex(unsigned long nbr)
{
 int i = 0;
 char * r;
 unsigned long arr[20];
  while(nbr > 15)
   {
     unsigned long o = nbr / 16;
     arr[i] = nbr - (o * 16);
     if(o  <  16)
     arr [i+1] = o;
     nbr /= 16;
     i++;
    }
  r = malloc(i+1);   
   int j = 0;
   while(i > -1)
    {
      r[j] = hex(arr[i]);
      j++; i--;
    }  
   return r;
}

