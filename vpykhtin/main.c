#include "libmx.h"
#include <stdio.h>
#include <fcntl.h>

int main(int c, char **v)
{
  printf("%d",mx_errorcase_1(c, v[1]));
}
