#include"libmx.h"
char *mx_itoa(int number)
{
  char * res;
  int arr[20];
  int i = 0;
  int long n = number;
  if(number < 0) n *= -1;
  while(n)
    {
      arr[i] = n % 10;
	n /=10;
	i++;
    }
  res = malloc(i);
  int j = 0;
  if(number < 0)
    {
      res[j] = '-';j++;
    }
  if(number == 0) res[j] = '0';
  while(i)
    {
      res[j] = arr[i - 1] + 48;
      j++; i--;
    }
  return res;
}
