/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:19:20 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:42:42 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	is_valid_rgb_value(char *s, int v)
{
	if (v < 0 || v > 255 || ft_str_isdigit(s) == 0)
		return (false);
	return (true);
}

/*
Returns true if s can be converted to rgb
*/
bool	validate_rgb(char *s)
{
	char	**tmp_list;

	if (!s)
		return (false);
	tmp_list = ft_split(s, ',');
	if (split_len(tmp_list) != 3)
	{
		free_split(tmp_list);
		return (false);
	}
	if (is_valid_int_list(tmp_list, is_valid_rgb_value) == false)
	{
		free_split(tmp_list);
		return (false);
	}
	free_split(tmp_list);
	return (true);
}
