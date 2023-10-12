/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:16 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/12 10:34:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	map(int a, int b, int i, int max)
{
	return ((b - a) * i / max + a);
}

static int	getcolor(int n, const int maxiter, int *palete, int ncolpalete)
{
	int	i;

	if (n == maxiter)
		return (palete[ncolpalete - 1]);
	i = 1;
	while (n > i * (maxiter / (ncolpalete - 1)))
		i++;
	return (map(palete[i - 1], palete[i], n, maxiter));
}

static int	getcolorpaletes1(int actv_pal, int n, const int maxiter)
{
	static int	palete1[5] = {ELECTRIC_BLUE, MAGENTA_BURST, LAVA_RED, \
		LIME_SHOCK, BLACK};
	static int	palete2[5] = {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121};
	static int	palete3[5] = {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700};
	static int	palete4[5] = {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF};
	int			color;

	if (actv_pal == 1)
		color = getcolor(n, maxiter, palete1, 5);
	else if (actv_pal == 2)
		color = getcolor(n, maxiter, palete2, 5);
	else if (actv_pal == 3)
		color = getcolor(n, maxiter, palete3, 5);
	else
		color = getcolor(n, maxiter, palete4, 5);
	return (color);
}

static int	getcolorpaletes2(int actv_pal, int n, const int maxiter)
{
	static int	palete5[6] = {0xE6E2AF, 0xA7A37E, 0xEFECCA, 0x046380, \
		0x002F2F, BLACK};
	static int	palete6[9] = {MAGENTA_BURST, ELECTRIC_BLUE, LIME_SHOCK, \
		NEON_ORANGE, PSYCHEDELIC_PURPLE, AQUA_DREAM, HOT_PINK, LAVA_RED, BLACK};
	static int	palete7[2] = {BLACK, WHITE};
	int			color;

	if (actv_pal == 5)
		color = getcolor(n, maxiter, palete5, 6);
	else if (actv_pal == 6)
		color = getcolor(n, maxiter, palete6, 9);
	else
		color = getcolor(n, maxiter, palete7, 2);
	return (color);
}

int	setcolor(int actv_pal, int n, const int maxiter)
{
	if (actv_pal > 0 && actv_pal < 5)
		return (getcolorpaletes1(actv_pal, n, maxiter));
	else
		return (getcolorpaletes2(actv_pal, n, maxiter));
}
