/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mystrtod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:45:20 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/11 15:51:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Number in string to double
 * The fist sign found is the double' sign
 * Avoid ' ' , and other print chars in the range 9 to 13
 *
 * No check to avoid Double Limits Values 
 * No check no well formated doubles numbers in string 
 */

static double	avoid_spaces_getsign(const char **p)
{
	double	sign;

	sign = 1.0;
	while (**p == 32 || (**p > 8 && **p < 14))
		(*p)++;
	if (**p == '-')
		sign = -1.0;
	if (**p == '+' || **p == '-')
		(*p)++;
	return (sign);
}

static double	mypow(double base, int exp)
{
	double	result;

	result = 1.0;
	while (exp-- > 0)
		result *= base;
	return (result);
}

double	ft_mystrtod(const char *str)
{
	double	result;
	double	decimal;
	double	sign;
	int		i;

	result = 0.0;
	decimal = 0.0;
	i = 0;
	sign = avoid_spaces_getsign(&str);
	while (*str != '.' && (*str >= '0' && *str <= '9'))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str != '.' && (*str >= '0' && *str <= '9'))
	{
		decimal = decimal * 10.0 + (*str - '0');
		str++;
		i++;
	}
	decimal /= mypow(10.0, i);
	result = sign * (result + decimal);
	return (result);
}
