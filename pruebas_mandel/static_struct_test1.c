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

	if (!md.hasbeeninit)
	{
		printf("!!!First Call to foo(). Next call to foo() values are going to change\n");
		md.hasbeeninit = 1;
	}
	else
	{
		md.minre = -2.0;
		md.maxre = 1.0;
		md.minim = -1.5;
		md.maxim = 1.5;
		md.re_factor = 0.5;
		md.im_factor = 0.5;
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
    printf("\tmandeldata.maxim = %f\n", mandeldata.maxim);
	i++;
}

int main()
{
    mdprint(foo());
    mdprint(foo());
    return (0);
}
