#include "libmx.h"

bool mx_errorcase_2(char * v)
{	
	char * s = mx_file_to_str(v);

	char **arr_of_isl;
    int res = 0;
	arr_of_isl = mx_ss(s, '-', ',', '\n');	
	int size = count_lines(s) * 3 -2;

	for(int i = 1; i < size; i++)
	{
		if (i != size-1) {
			while(mx_strcmp(arr_of_isl[i], "*") == 0)
			i++;
	
		}
		if(isdigits(arr_of_isl[i])) i++;
		for(int j = i+1; j < size -1; j++)
		{
			if(mx_strcmp(arr_of_isl[i],arr_of_isl[j]) == 0 || isdigits(arr_of_isl[j])) {
				arr_of_isl[j] = "*";
			}
		}
		res++;
	}
	printf("%d    %d\n",  digits(arr_of_isl[0]),res);
if(res != digits(arr_of_isl[0]))
{
	printer("error: invalid number of islands");
	return 0;
}
return 1;
}

