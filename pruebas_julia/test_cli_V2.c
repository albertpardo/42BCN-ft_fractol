#include <stdio.h>
#include <stddef.h>
#include "cli.h"


static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void printinfo()
{
	printf("Choose the number from the next fractals:\n");
	printf("\t- 1) Mandelbrot fractal.\n");
	printf("\t- 2) Julia fractal\n");
	printf("\t- 3) TODEFINE fractal\n");
	printf("\nUsage: \n");
	printf("./fractol [Fractal_Number]\n\n");
	printf("Julia has two optional params. Julia usage:\n");
	printf("./fractol [Fractal_Number] [real] [imaginary]\n\n");
	printf("Info for Julia params :\n");
 	printf("- They must comply: (real^2 + imaginary^2) =< 4.\n");
 	printf("- There are default values when [real] and [imaginary] are not indicated.\n");
	printf("- There is not valid put only [real] or [imaginary].\n\n");
	printf("Examples of use:\n");
	printf("\t- Maldebrot: ./fractol 1\n");
	printf("\t- Julia    : ./fractol 2\n");
	printf("\t- Julia    : ./fractol 2 -0.4 0.5\n");
}

static void printnovalid()
{
	printf("||   No  valid arguments.  ||\n\n");
	printinfo();
}

int	main(int argc, char **argv)
{
	int		i;
	double	re;
	double	im;
	
	if (argc == 2 || argc == 4)
	{
		if (argc == 2 && ft_strlen(argv[1]) == 1)
		{
			if (argv[1][0] == '1')
				printf("Maldenbrot selected\n");
			else if (argv[1][0] == '2')
				printf("Julia selected without arguments\n");
			else if (argv[1][0] == '3')
				printf("TODEFINE fractal selected\n");
			else
				printnovalid();
		}
		else if (argc == 4 && ft_strlen(argv[1]) == 1)
		{
			 if (argv[1][0] == '2')
			 {
				printf("Julia selected with arguments.\n");
				printf("\tArguments to be tested : '%s' and '%s'\n", argv[2], argv[3]);
				if (istrtodoublevalidformat(argv[2]) && istrtodoublevalidformat(argv[3]))
				{
					printf("\tArguments are validated. Conversion: \n");
					printf("\t\treal = %f, imaginary = %f\n", ft_mystrtod(argv[2]),ft_mystrtod(argv[3]));
				}
				else
					printf("NO VALID ARGUMENTS !!!\n");
			 }
			 else
				printnovalid();
		}
		else
			printnovalid();
	}
	else
		printnovalid();
	return(0);
}
