#include "libmx.h"

int digits(char *c)
{
    int res = 0;
    int i = 0;

    while(c[i]) {
        res = res *10 + c[i] - 48;
        i++;
    }
    return res;
}
