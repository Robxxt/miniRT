/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:31:14 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 10:34:28 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	validate_pl(char **s)
{
	int	len;

	len = split_len(s);
	if (!s || (len != 4 && len != 5))
		return (false);
	if (ft_strncmp("pl", s[0], 3) != 0)
		return (false);
	if (validate_coord(s[1]) == false)
		return (false);
	if (validate_3d_normalized_vector(s[2]) == false)
		return (false);
	if (validate_rgb(s[3]) == false)
		return (false);
	if (len == 5 && is_valid_texture(s[4], 1) == false)
		return (false);
	return (true);
}
