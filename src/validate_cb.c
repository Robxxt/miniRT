/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/17 15:31:44 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	validate_cb(char **s)
{
	int	len;

	len = split_len(s);
	if (!s || (len != 6 && len != 7))
		return (false);
	if (ft_strncmp("cb", s[0], 3) != 0)
		return (false);
	if (validate_coord(s[1]) == false)
		return (false);
	if (validate_3d_normalized_vector(s[2]) == false)
		return (false);
	if (validate_3d_normalized_vector(s[3]) == false)
		return (false);
	if (is_valid_float_number(s[4]) == false)
		return (false);
	if (validate_rgb(s[5]) == false)
		return (false);
	if (len == 7 && is_valid_texture(s[6]) == false)
		return (false);
	return (true);
}