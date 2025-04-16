#include <stdio.h>

typedef struct initial_mandel_data
{
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_factor;
	double	im_factor;
}				t_initmandel;

int main()
{
    t_initmandel    mandeldata;
    
    printf("mandeldata.minre = %f\n", mandeldata.minre);
    printf("mandeldata.maxre = %f\n", mandeldata.maxre);
    printf("mandeldata.minim = %f\n", mandeldata.minim);
    printf("mandeldata.maxim = %f\n", mandeldata.maxim);
    return (0);
}
