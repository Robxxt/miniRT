/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:13:48 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:45:06 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Returns true if is a valid formatted A element.
*/
bool	validate_element_a(char **s)
{
	float	n;

	if (!s || split_len(s) != 3)
		return (false);
	if (is_valid_float_number(s[1]) == false || validate_rgb(s[2]) == false)
		return (false);
	n = ft_atof(s[1]);
	if (n < 0 || n > 1)
		return (false);
	return (true);
}
