/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:31:02 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 14:47:14 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Return true if the format of the line is correct.
*/
bool	check_element(char **s)
{
	if (is_valid_element_type(s[0]) == false)
		return (false);
	if (ft_strncmp(s[0], "A", 2) == 0)
		if (validate_element_a(s) == false)
			return (false);
	if (ft_strncmp(s[0], "C", 2) == 0)
		if (validate_element_c(s) == false)
			return (false);
	if (ft_strncmp(s[0], "L", 2) == 0)
		if (validate_element_l(s) == false)
			return (false);
	if (ft_strncmp(s[0], "pl", 2) == 0)
		if (validate_pl(s) == false)
			return (false);
	if (ft_strncmp(s[0], "cy", 2) == 0)
		if (validate_cy(s) == false)
			return (false);
	if (ft_strncmp(s[0], "sp", 2) == 0)
		if (validate_sp(s) == false)
			return (false);
	return (true);
}

/*
Returns true if the whole file content is correct.
*/
bool	has_valid_content(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (check_element(tmp->content) == false)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
