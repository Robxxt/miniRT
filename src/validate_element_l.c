/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element_l.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:46:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 16:27:31 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

// bool	is_valid_coor(char *s)

/*
Returns true if is a valid formatted L element.
*/
bool	validate_element_l(char **s)
{
	float	n;

	if (!s || split_len(s) != 4)
		return (false);
	if (is_valid_float_number(s[1]) == false || validate_rgb(s[2]) == false)
		return (false);
	n = ft_atof(s[1]);
	if (n < 0 || n > 1)
		return (false);
	return (true);
}