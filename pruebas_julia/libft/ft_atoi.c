/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:15:16 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/11 11:38:56 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Number in string to integer
 * The fist sign found is the integer' sign
 * Avoid ' ' , and other print chars in the range 9 to 13 
 */

int	ft_atoi(const char *str)
{
	int				result;
	int				sign;
	unsigned char	*p;

	result = 0;
	sign = 1;
	p = (unsigned char *) str;
	while (*p == 32 || (*p > 8 && *p < 14))
		p++;
	if (*p == '-')
		sign = -1;
	if (*p == '+' || *p == '-')
		p++;
	while (*p != '\0' && (*p >= '0' && *p <= '9'))
	{
		result = result * 10 + sign * (*p - '0');
		p++;
	}
	return (result);
}
