#include <stdlib.h>
#include <float.h>
#include <stdio.h>

int main(void)
{
	printf("Storage size for double : %lu \n", sizeof(double));
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
	return (0);
}
