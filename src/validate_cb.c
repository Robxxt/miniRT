/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/27 15:13:06 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	validate_cb(char **s)
{
	if (!s || split_len(s) != 4)
		return (false);
	if (ft_strncmp("cb", s[0], 3) != 0)
		return (false);
	if (validate_coord(s[1]) == false)
		return (false);
	if (validate_3d_normalized_vector(s[2]) == false)
		return (false);
	if (validate_rgb(s[3]) == false)
		return (false);
	return (true);
}