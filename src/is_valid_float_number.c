/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_float_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:26:13 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:36:00 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static bool	is_valid_digit(char c)
{
	if (ft_isdigit(c) || c == '.' || c == '-' || c == '+')
		return (true);
	return (false);
}

/*
Returns true if the string can be converted to a float.
False otherwise.
*/
bool	is_valid_float_number(char *str)
{
	int	point_counter;
	int	plus_counter;
	int	minus_counter;
	int	i;

	if (!str || !str[0])
		return (false);
	point_counter = 0;
	plus_counter = 0;
	minus_counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			point_counter++;
		if (str[i] == '+')
			plus_counter++;
		if (str[i] == '-')
			minus_counter++;
		if (!is_valid_digit(str[i])
			|| (point_counter > 1 || minus_counter > 1 || plus_counter > 1)
			|| (minus_counter >= 1 && plus_counter >= 1))
			return (false);
		i++;
	}
	if (get_integer_part(str) > INT_MAX - 1)
		return (false);
	if (get_integer_part(str) < INT_MIN + 1)
		return (false);
	return (true);
}
