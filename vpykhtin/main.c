#include "libmx.h"
#include <stdio.h>
#include <fcntl.h>

int main(int c, char **v)
{
	if(c > 1) {
 //printf("%d",mx_errorcase_1(c, v[1]));
  		mx_errorcase_2(v[1]);
	}
}
