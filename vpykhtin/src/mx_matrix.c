#include "libmx.h"
int str_mid(const char *s, char c, char d, char f)
{
    int count = 0;
    while(*s != c && *s != d && *s != f && *s != '\0' && isdigits((char )*s))
    {
	count++;
        s++;
    }
    return count;
}
char **mx_onlywords(const char *r, char c, char f, char d)
{

	char *s =  (char *)r;
    int size = count_lines(s) * 3 -2;
    char **arr = malloc((size + 1) * sizeof(char *));
    for(int i = 0; i < size; i++)
    {
	while((*s == c || *s == d || isdigits((char )*s)|| *s == f )&& *s != '\0')
	{
	    s++;
	}
	arr[i] = mx_strnew(str_mid(s, c, d,f));
	int j = 0;
	while(*s != c && !isdigits((char )*s) && *s != d && *s != f && *s != '\0')
	{
	    arr[i][j] = *s;
	    s++;
	    j++;
	}
    }
    arr[size] = NULL;
    return arr;
}
void mx_matrix(char *v)
{
    char *s = mx_file_to_str(v);
    char **arr = mx_onlywords(s, '-', ',', '\n');
    // int mx_matrix[arr[0]][arr[0]];
    // char **arr_isl;
	printf("%s\n", arr[0]);

}

