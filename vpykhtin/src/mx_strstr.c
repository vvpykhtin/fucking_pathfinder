#include "libmx.h"
char *mx_strstr(const char *haystack, const char *needle)
{
    while(*haystack != '\0')
    {
	if (*haystack == *needle)
	{
	    int i = 0;
	    const char *s = haystack;
	    while(*s == needle[i])
	    {
		i++;
		s++;
		if (needle[i] == '\0')
		{
		    return (char *)haystack;
		}
	   }
	}
	if (*haystack != '\0')
	{
	    haystack++;
	}
    }
    return NULL;
}
