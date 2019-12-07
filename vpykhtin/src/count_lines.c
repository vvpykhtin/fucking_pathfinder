#include "libmx.h"
int count_lines(char *v)
{
	int result = 0;
	for(int i = 0; i < mx_strlen(v);i++)
	{

		if(v[i] == '\n' && v[i-1] != '\n')
			result++;
	}
	if(v[0] == '\n') result--;
	return result;
}
