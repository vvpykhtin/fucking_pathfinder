#include "libmx.h"

int main(int c, char **v)
{
	if (mx_error(c,v[1]))
		printf("%s\n", "hui");
	mx_matrix(v[1]);
}
