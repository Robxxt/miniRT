/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:31:02 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 08:57:27 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Return true if the format of the line is correct.
*/
bool	check_element(char **s)
{
	return (is_valid_element_type(s[0]));
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
	// print_lst(lst);
	return (true);
}