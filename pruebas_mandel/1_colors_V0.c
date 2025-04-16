/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_colors_V0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:20:02 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/28 14:30:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* 
 * setcolor(int n, const int maxiter)
 *
 * Put n to a color so that from 0 to maxiter/2-1.
 * The color goes from black (0x0) to red(0x00FF0000) and from maxiter/2 to
 * maxiter. The color goes from red(0x00FF0000) to white(0x00FFFFFF)
 */

int	setcolor(int n, const int maxiter)
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
