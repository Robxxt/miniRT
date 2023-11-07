/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:13:48 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 09:26:20 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	validate_element_a(char **s)
{
	if (!s || !s[1])
		return (false);
	if (is_valid_float_number(s[1]) == false)
		return (false);
	return (true);
}