/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:16 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/14 22:46:04 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static int	map(int a, int b, double f)
{
	if (b > a)
		return ((b - a) * f + a);
	return (a - (a - b) * f);
}

static int	getcolor(int n, const int maxiter, int *palete, int ncolpalete)
{
	int		i;
	double	step;
	double	fpos;

	step = (double)(ncolpalete - 1) / maxiter;
	fpos = n * step;
	i = (int) fpos;
	if (n == maxiter)
		return (palete[ncolpalete - 1]);
	else
		return (map(palete[i], palete[i + 1], fpos - i));
}

static int	getcolorpaletes1(int actv_pal, int n, const int maxiter)
{
	static int	palete1[5] = {0x0066FF, 0xFF00FF, 0xFF3300,	0xCCFF00, BLACK};
	static int	palete2[10] = {0x2f4f4f, 0x006400, 0x4b0082, 0xff0000, \
		0xffa500, 0xffff00, 0xff0f0f, 0x00fa9a, 0x00ffff, BLACK};
	static int	palete3[6] = {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, \
		0xA1D700, BLACK};
	static int	palete4[5] = {0xE7DFE8, 0xEDE3E4, 0xE4DEE4, 0xAF9FA5, BLACK};
	int			color;

	if (actv_pal == 1)
		color = getcolor(n, maxiter, palete1, 5);
	else if (actv_pal == 2)
		color = getcolor(n, maxiter, palete2, 10);
	else if (actv_pal == 3)
		color = getcolor(n, maxiter, palete3, 6);
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
	static int	palete7[5] = {WHITE, MAGENTA_BURST, AQUA_DREAM, WHITE, BLACK};
	int			color;

	if (actv_pal == 5)
		color = getcolor(n, maxiter, palete5, 6);
	else if (actv_pal == 6)
		color = getcolor(n, maxiter, palete6, 9);
	else
		color = getcolor(n, maxiter, palete7, 5);
	return (color);
}

int	setcolor(int actv_pal, int n, const int maxiter)
{
	if (actv_pal > 0 && actv_pal < 5)
		return (getcolorpaletes1(actv_pal, n, maxiter));
	else
		return (getcolorpaletes2(actv_pal, n, maxiter));
}
