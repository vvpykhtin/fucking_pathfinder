#include "libmx.h"

bool mx_error(int c, char *v)
{
    if (c != 2) { 
        printer("usage: ./pathfinder [filename]"); 
        return 0;
    }
    if (!mx_errorcase_1(c,v) || !mx_errorcase_2(v))
        return 0;
    return 1;
}
