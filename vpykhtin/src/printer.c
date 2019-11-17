#include "libmx.h"
void printer(char *c)
{
  write(2, c, mx_strlen(c));
}
