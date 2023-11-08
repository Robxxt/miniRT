/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 08:35:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	is_3d_normalized_vector(char *s, float f)
{
	float	val;

	(void)f;
	val = ft_atof(s);
	return (is_valid_float_number(s) && (val >= -1 && val <= 1));
}

bool	validate_3d_normalized_vector(char *s)
{
	char	**tmp_lst;

	tmp_lst = ft_split(s, ',');
	if (split_len(tmp_lst) != 3)
		return (false);
	if (is_valid_float_list(tmp_lst, is_3d_normalized_vector) == false)
	{
		free_split(tmp_lst);
		return (false);
	}
	free_split(tmp_lst);
	return (true);
}

bool	is_valid_angle(int d)
{
	if (d < 0 || d > 180)
		return (false);
	return (true);
}

/*
Returns true if is a valid formatted C element.
*/
bool	validate_element_c(char **s)
{
	int	degrees;

	if (!s || split_len(s) != 4)
		return (false);
	if (validate_coord(s[1]) == false || validate_3d_normalized_vector(s[2]) == false)
		return (false);
	if (ft_str_isdigit(s[3]) == 0)
		return (false);
	degrees = ft_atoi(s[3]);
	return (is_valid_angle(degrees));
}
