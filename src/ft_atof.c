/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 05:12:02 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 12:02:43 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Receives a string and returns a float containing only the float part
of the number.
*/
float	get_float_part(char *str)
{
	int		i;
	float	result;
	int		sign;
	int		decimals;

	if (!is_valid_float_number(str))
		return (0.0);
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	while (str[i] && str[i] != '.')
		i++;
	decimals = 0;
	result = 0.0;
	while (str[i] && str[i + 1] && decimals < 7)
	{
		i++;
		decimals++;
		result += pow(10, -decimals) * (float)(str[i] - '0');
	}
	return (result * sign);
}

/*
Receives a string and returns an integer ignoring the floating part.
*/
int	get_integer_part(char *str)
{
	long	tmp;
	int		result;
	int		sign;
	int		i;

	tmp = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		tmp = tmp * 10 + str[i] - '0';
		i++;
	}
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (INT_MAX);
	result = (int)tmp;
	return (result * sign);
}

/*
Converts a string to a that is guaranteed to be precize for 1 decimal value.
* The string str first must be validated as a valid formatted float.
This function does return 0 if is not a valid float.=
*/
float	ft_atof(char *str)
{
	float	result;

	if (is_valid_float_number(str) == false)
		return (0);
	result = 0.0;
	result = (float)get_integer_part(str) + get_float_part(str);
	return (result);
}
