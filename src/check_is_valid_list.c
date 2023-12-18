/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:07 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 13:13:18 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	is_valid_int_list(char **list, bool (*function)(char *, int))
{
	int	tmp;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (ft_str_isdigit(list[i]) == 0)
			return (false);
		tmp = ft_atoi(list[i]);
		if (function(list[i], tmp) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_float_list(char **list, bool (*function)(char *, float))
{
	int	tmp;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (is_valid_float_number(list[i]) == 0)
			return (false);
		tmp = ft_atof(list[i]);
		if (function(list[i], tmp) == false)
			return (false);
		i++;
	}
	return (true);
}
