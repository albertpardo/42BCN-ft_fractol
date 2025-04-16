#include <stdio.h>

void printinfo()
{
		printf(" Usage: \n");
		printf("./fractol [Fractal_Number] [real_value]* [imaginary_value]*\n\n");
		printf("- Options for [Fractal_Number] argument:\n");
		printf("\t- Mandelbrot fractal -> 1\n");
		printf("\t- Julia fractal      -> 2\n");
	 	printf("- Arguments [real_value]* [imaginary_value]* are only for Julia Fractal.They are optional and must comply: (real_value^2 + imaginary_value^2) =< 4  : \n");
	 	printf("\tThere are default values when [real_value]* and [imaginary_value]* are not indicated. There is not valid put only [real_value]* or [imaginary_value]* \n\n");
		printf("Examples of use:\n");
		printf("\t- Maldebrot: ./fractol 1\n");
		printf("\t- Julia    : ./fractol 2\n");
		printf("\t- Julia    : ./fractol 2 -0.4 0.5\n");
}



int	main(int argc, char **argv)
{
	int	i;
	
	if (argc == 2 || argc == 4)
	{
		i = 1;
		while (i < argc)
			printf("%s\n", argv[i++]);
	}
	else
		printinfo();
	return(0);
}
