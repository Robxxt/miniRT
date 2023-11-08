/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:35:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 08:43:41 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	validate_sp(char **s)
{
	if (!s || split_len(s) != 4)
		return (false);
	if (ft_strncmp("sp", s[0], 3) != 0)
		return (false);
	if (validate_coord(s[1]) == false)
		return (false);
	if (is_valid_float_number(s[2]) == false)
		return (false);
	if (validate_rgb(s[3]) == false)
		return (false);
	// if (ft_str_isdigit(s[3]) == 0)
	// 	return (false);
	// degrees = ft_atoi(s[3]);
	// return (is_valid_angle(degrees));
	return (true);
}
