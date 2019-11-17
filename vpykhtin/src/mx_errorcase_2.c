#include"libmx.h"

bool mx_errorcase_2(char * v)
{	
	char * s = mx_file_to_str(v);
	int count_n = 0;
	for(int i = 0; s[i]; i++)
	  {
	    if(s[i] == '\n') count_n++;
	  }
	char **arr = NULL;
	arr =  mx_strsplit(s, '\n');
	//int count_islands = digits(arr[0]);
	//printf("%s , %d", arr[3], count_islands);
	int a = 0; int b = 0;
	char arr_is[(count_n -1)*2][1000000];
	for(int i = 1; i < count_n; i++)
		{
			for(int j = 0; arr[i][j]!= ','; j++)
			{
				if(arr[i][j]== '-') {
					j++; 
					a++; 
					b = 0;
				} 
					arr_is[a][b] = arr[i][j];
					b++;
			}
			a++;
			b = 0;
		}
		printf("%s", arr_is[0]);
	return 0;
}

