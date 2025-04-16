#include <stdio.h>

typedef struct initial_mandel_data
{
	int		hasbeeninit;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_factor;
	double	im_factor;
}				t_initmandel;


t_initmandel foo()
{
    static t_initmandel	md;
	double				k = 0.3;

	if (!md.hasbeeninit)
	{
		printf("!!!first call to foo(). Set initial values. Next call to foo() values are going to change\n");
		md.hasbeeninit = 1;
		md.minre = -2.0;
		md.maxre = 1.0;
		md.minim = -1.5;
		md.maxim = 1.5;
		md.re_factor = 0.5;
		md.im_factor = 0.5;
	}
	else
	{
		printf("!!!New values in foo()\n");
		md.minre *= k;
		md.maxre *= k;
		md.minim *= k;
		md.maxim *= k;
		md.re_factor *= k;
		md.im_factor *= k;
	}
	return(md);
}

void mdprint(t_initmandel mandeldata)
{
	static int i = 1;

	printf("> i = %d ------------\n", i);
	printf("\tmandeldata.hasbeeninit = %d\n", mandeldata.hasbeeninit);
	printf("\tmandeldata.minre = %f\n", mandeldata.minre);
    printf("\tmandeldata.maxre = %f\n", mandeldata.maxre);
    printf("\tmandeldata.minim = %f\n", mandeldata.minim);
    printf("\tmandeldata.maxim = %f\n\n", mandeldata.maxim);
	i++;
}

int main()
{
    mdprint(foo());
    mdprint(foo());
    mdprint(foo());
    mdprint(foo());
    mdprint(foo());
    return (0);
}
