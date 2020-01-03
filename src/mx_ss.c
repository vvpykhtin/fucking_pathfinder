#include"pathfinder.h"
int str_mod(const char *s, char c, char d, char f)
{
    int count = 0;
    while(*s != c && *s != d && *s != f && *s != '\0')
    {
	count++;
        s++;
    }
    return count;
}
char **mx_ss(const char *r, char c, char f, char d)
{
    if (r == NULL || !c)
    {
	return NULL;
    }
char *s =  (char *)r;
    int size = count_lines(s) * 3 -2;
    char **arr = malloc((size + 1) * sizeof(char *));
    for(int i = 0; i < size; i++)
    {
	while((*s == c || *s == d || *s == f )&& *s != '\0')
	{
	    s++;
	}
	arr[i] = mx_strnew(str_mod(s, c, d,f));
	int j = 0;
	while(*s != c && *s != d && *s != f && *s != '\0')
	{
	    arr[i][j] = *s;
	    s++;
	    j++;
	}
    }
    arr[size] = NULL;
    return arr;
}
