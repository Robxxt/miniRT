/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 05:12:02 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/06 06:18:16 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	get_integer_part(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
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
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*
Converts a string to a floating value with 1 decimal value.
* The string str first must be validated as a valid formatted float.
This function does return 0 if is not a valid float.=
*/
float	ft_atof(char *str)
{
	if (is_valid_number(str) == false)
		return (0);
	return (123);
}
