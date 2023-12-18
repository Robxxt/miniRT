/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:35:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:42:29 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	validate_sp(char **s)
{
	int	len;

	len = split_len(s);
	if (!s || (len != 4 && len != 5))
		return (false);
	if (ft_strncmp("sp", s[0], 3) != 0)
		return (false);
	if (validate_coord(s[1]) == false)
		return (false);
	if (is_valid_float_number(s[2]) == false)
		return (false);
	if (validate_rgb(s[3]) == false)
		return (false);
	if (len == 5 && is_valid_texture(s[4], 0) == false)
		return (false);
	return (true);
}
