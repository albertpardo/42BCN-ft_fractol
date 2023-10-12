/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 09:47:45 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/11 14:03:10 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* 
 * double	ft_mystrtod(const char *str)
 *
 * Number in string to double
 * The fist sign found is the double' sign
 * Avoid ' ' , and other print chars in the range 9 to 13
 *
 * No check to avoid Double Limits Values
 * No check no well formated doubles numbers in string
 */

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

static int	countchar(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int	istrtodoublevalidformat(const char *str)
{
	const char	*p;
	int			nplus;
	int			nminus;

	p = str;
	while (*p == '+' || *p == '-' || *p == '.' || (*p >= '0' && *p <= '9'))
		p++;
	nplus = countchar(str, '+');
	nminus = countchar(str, '-');
	if (*p != '\0' || countchar(str, '.') > 1 \
				|| nplus > 1 || nminus > 1 || (nplus == 1 && nminus == 1))
		return (0);
	else
		return (1);
}
