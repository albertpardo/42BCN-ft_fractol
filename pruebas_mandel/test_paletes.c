#include <stdio.h>
 #include <stdlib.h>

/*
 * COLORS
*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct	s_palete
{
	int	nclrs;
	const int *palete;
}				t_palete;

int	*paletedup(int ncolors, const int *pal)
{
	int *p;
	int i;

	p = (int *) malloc(sizeof(int) * ncolors);

	if (p != NULL)
	{
		i = 0;
		while (i < ncolors)
		{
			p[i] = pal[i];
			i++;
		}
	}
	return (p);
}

static t_palete  *cretepalete(int nclrs, const int *pal)
{
	t_palete	palete;
	int			p;

	p = paletedup(nclrs, pal)
	if (p != NULL)
	{
		palete.nclrs = nclrs;
		palete.palete = pal;
	}

	return (palete);
}

/*
t_palete *setpaletes()
{
	t_palete	*paletes[8];


}
*/

int main(void)
{
	const int	palete1[5] = { ELECTRIC_BLUE, MAGENTA_BURST, LAVA_RED, LIME_SHOCK, BLACK};
	const int	palete2[5] = {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121};
	const int	palete3[5] = {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700};
	const int	palete4[5] = {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF};
	const int	palete5[6] = {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF, BLACK};
	const int palete6[9] = {MAGENTA_BURST, ELECTRIC_BLUE, LIME_SHOCK, NEON_ORANGE, PSYCHEDELIC_PURPLE, AQUA_DREAM, HOT_PINK,  LAVA_RED, BLACK};
	const int palete7[2] = {WHITE, BLACK};
	t_palete	paletes[7];

	t_palete *pal;
	int i = 0;

	pal = createpalete(5, palete1);
	paletes[0] = pal;
	
	printf("n = %d\n", paletes[0].nclrs);
	while(i < paletes[0].nclrs)
		printf("%X ,", paletes[0].palete[i++]);
	printf("\n");

	return (0);
}
