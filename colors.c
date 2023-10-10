/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:16 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/09 15:33:19 by apardo-m         ###   ########.fr       */
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

/*
static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
*/


/* 
 * setcolor(int n, const int maxiter)
 *
 TE* Put n to a color so that from 0 to maxiter/2-1.
 * The color goes from black (0x0) to red(0x00FF0000) and from maxiter/2 to
 * maxiter. The color goes from red(0x00FF0000) to white(0x00FFFFFF)
 */

/*
static int	setcolorbrw(int n, const int maxiter)
{
	int	component;

	component = n * 0xFF * 2 / maxiter;
	if (n < (maxiter / 2))
		return (create_trgb(0x00, component, 0x0, 0x0));
	else if (n < maxiter)
		return (create_trgb(0x00, 0xFF, component, component));
	else
		return (0xFF000000);
}
*/

static	int map(int a, int b, int i, int max)
{
	return ( (b -a) * i / max + a);
}

/*
int	setcolor(int n, const int maxiter)
{
	return (map(LAVA_RED, ELECTRIC_BLUE, n, maxiter));
}
*/

/*
int	setcolor(int n, const int maxiter)
{
	int	palete[] = { MAGENTA_BURST, LAVA_RED, ELECTRIC_BLUE};
	
	if ( n == maxiter)
		return (palete[2]);
	else if (n < (maxiter / 2))
		return (map(palete[0], palete[1], n, maxiter));
	else
		return (map(palete[1], palete[2], n, maxiter));
}
*/

static	int getcolor(int n, const int maxiter, int *palete, int ncolpalete)
{
	int	i;

	if ( n == maxiter)
		return (palete[ncolpalete - 1]);
	i = 1;
	while (n > i * (maxiter / (ncolpalete - 1)))
		i++;	
	return (map(palete[i - 1], palete[i], n, maxiter));
}	

int	setcolor(int actv_pal, int n, const int maxiter)
{
	int	palete1[5] = { ELECTRIC_BLUE, MAGENTA_BURST, LAVA_RED, LIME_SHOCK, BLACK};
	int	palete2[5] = { 0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121};
	int	palete3[5] = { 0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700};
	int	palete4[5] = { 0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF};
	int	palete5[6] = { 0xE6E2AF, 0xA7A37E, 0xEFECCA, 0x046380, 0x002F2F, BLACK};
	int palete6[9] = { MAGENTA_BURST, ELECTRIC_BLUE, LIME_SHOCK, NEON_ORANGE, PSYCHEDELIC_PURPLE, AQUA_DREAM, HOT_PINK,  LAVA_RED, BLACK};
	int palete7[2] = { WHITE, BLACK};
	int color;

	if (actv_pal == 1)
		color = getcolor(n, maxiter, palete1, 5);
	else if (actv_pal == 2)
		color = getcolor(n, maxiter, palete2, 5);
	else if (actv_pal ==  3)
		color = getcolor(n, maxiter, palete3, 5);
	else if (actv_pal == 4)
		color = getcolor(n, maxiter, palete4, 5);
	else if (actv_pal == 5)
		color = getcolor(n, maxiter, palete5, 6);
	else if (actv_pal == 6)
		color = getcolor(n, maxiter, palete6, 9);
	else 
		color = getcolor(n, maxiter, palete7, 2);
	return (color);
}

/*
int hsvtorgb(double h, double s, double v)
{
	double	r;
	double	g;
	double	b;
	double	f;
	double	p;
	double	q;
	double	t;
	double	hf;
	int		i;

	r = 0.0;
	g = 0.0;
	b = 0.0;
	while (h < 0.0)
   		h += 360.0;
	while (h >= 360.0)
   		h -= 360.0;
	if (s <= 0.0)
	{
		r = v;
		g = v;
		b = v;
	}
	else
	{
		hf = h / 60.0;
		i = (int)hf;
		f = hf - i;
		p = v * (1 - s);
		q = v * (1 - s * f);
		t = v * (1 - s * (1 - f));
		r = v;
		g = v;
		b = v;

		if (i == 0)
		{
			r = v;
			g = t;
			b = p;
		}
		else if (i == 1)
		{
			r = q;
			g = v;
			b = p;
		}
		else if (i == 2)
		{
			r = p;
			g = v;
			b = t;
		}
		else if (i == 3)
		{
			r = p;
			g = q;
			b = v;
		}
		else if (i == 4)
		{
			r = t;
			g = p;
			b = v;
		}
		else if (i == 5)
		{
			r = v;
			g = p;
			b = q;
		}
		else if (i == 6)
		{
			r = v;
			g = t;
			b = p;
		}
		else if (i == -1)
		{
			r = v;
			g = p;
			b = q;
		}
	}
	return (clamp((int)(r * 255.0)), clamp((int)(g * 255.0)), clamp((int)(b * 255.0));
}

int clamp(int i)
{
	if (i < 0) return (0);
	if (i > 255) return (255);
 	return (i);
}
*/
