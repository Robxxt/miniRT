/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:50:14 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/27 15:17:22 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Returns true if the element type is correct.
*/
bool	is_valid_element_type(char *type)
{
	if (!type)
		return (false);
	if (ft_strncmp(type, "A", 2) && ft_strncmp(type, "C", 2)
		&& ft_strncmp(type, "L", 2) && ft_strncmp(type, "pl", 3)
		&& ft_strncmp(type, "sp", 3) && ft_strncmp(type, "cy", 3) && ft_strncmp(type, "cb", 3))
	{
		return (false);
	}
	return (true);
}
