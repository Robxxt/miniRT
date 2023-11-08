/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element_l.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:46:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 07:40:13 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	is_valid_coor(char *s, float f)
{
	(void)f;
	return (is_valid_float_number(s));
}

bool	validate_coord(char *s)
{
	char	**tmp_lst;

	tmp_lst = ft_split(s, ',');
	if (split_len(tmp_lst) != 3)
		return (false);
	if (is_valid_float_list(tmp_lst, is_valid_coor) == false)
	{
		free_split(tmp_lst);
		return (false);
	}
	free_split(tmp_lst);
	return (true);
}

/*
Returns true if is a valid formatted L element.
*/
bool	validate_element_l(char **s)
{
	float	brightness;

	if (!s || (split_len(s) != 4 &&  split_len(s) != 3))
		return (false);
	if (is_valid_float_number(s[2]) == false || validate_coord(s[1]) == false)
		return (false);
	brightness = ft_atof(s[2]);
	if (brightness < 0 || brightness > 1)
		return (false);
	if (s[3])
	{
		if (validate_rgb(s[3]) == false)
			return (false);
	}
	return (true);
}