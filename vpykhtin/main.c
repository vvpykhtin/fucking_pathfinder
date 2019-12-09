#include "libmx.h"
#include <stdio.h>
#include <fcntl.h>


int main(int c, char **v)
{

	if(mx_errorcase_1(c, v[1]))
  		if(mx_errorcase_2(v[1]))
  		{
  			char * s = mx_file_to_str(v[1]);
  			char **arr = mx_ss(s, '-', ',', '\n');
  			char ** arr_lines = mx_strsplit(s, '\n');
  			mx_pathfinder(arr, arr_lines);
  		}
	printf("\n");
}
