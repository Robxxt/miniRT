/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:19:20 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 16:30:49 by rdragan          ###   ########.fr       */
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
	// i = 0;
	if (is_valid_int_list(tmp_list, is_valid_rgb_value) == false)
	{
		free_split(tmp_list);
		return (false);
	}
	// while (tmp_list[i])
	// {
	// 	tmp = ft_atoi(tmp_list[i]);
	// 	if (tmp < 0 || tmp > 255 || ft_str_isdigit(tmp_list[i]) == 0)
	// 	{
	// 		free_split(tmp_list);
	// 		return (false);
	// 	}
	// 	i++;
	// }
	free_split(tmp_list);
	return (true);
}