/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_float_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:26:13 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 12:54:34 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static bool	is_valid_digit(char c)
{
	if (ft_isdigit(c) || c == '.' || c == '-' || c == '+')
		return (true);
	return (false);
}

bool	check_extremes(char *s)
{
	if (get_integer_part(s) > INT_MAX - 1)
		return (false);
	if (get_integer_part(s) < INT_MIN + 1)
		return (false);
	return (true);
}

/*
Returns true if the string can be converted to a float.
False otherwise.
Counter[0] checks for how many points characters are.
Counter[1] checks for how many plus characters are.
Counter[2] checks for how many minus characters are.
*/
bool	is_valid_float_number(char *str)
{
	int	counter[3];
	int	i;

	if (!str || !str[0])
		return (false);
	i = 0;
	ft_bzero(counter, sizeof(int) * 3);
	while (str[i])
	{
		if (str[i] == '.')
			counter[0]++;
		if (str[i] == '+')
			counter[1]++;
		if (str[i] == '-')
			counter[2]++;
		if (!is_valid_digit(str[i])
			|| (counter[0] > 1 || counter[2] > 1 || counter[1] > 1)
			|| (counter[2] >= 1 && counter[1] >= 1))
			return (false);
		i++;
	}
	return (check_extremes(str));
}
