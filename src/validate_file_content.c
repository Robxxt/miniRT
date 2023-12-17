/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:31:02 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/17 12:25:03 by rdragan          ###   ########.fr       */
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
	if (ft_strncmp(s[0], "pl", 3) == 0)
		if (validate_pl(s) == false)
			return (false);
	if (ft_strncmp(s[0], "cy", 3) == 0)
		if (validate_cy(s) == false)
			return (false);
	if (ft_strncmp(s[0], "sp", 3) == 0)
		if (validate_sp(s) == false)
			return (false);
	if (ft_strncmp(s[0], "cb", 3) == 0)
	{
		if (validate_cb(s) == false)
			return (false);
	}
	return (true);
}

/*
Sets the first 3 numbers of a list to be 0.
*/
void	fill_with_zeros(int *lst)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		lst[i] = 0;
		i++;
	}
}

/*
Checks that A, C, L are at least ones in the file.
*/
bool	check_minimum_occurences(int *occurences)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (occurences[i] < 1)
			return (false);
		i++;
	}
	return (true);
}

/*
Returns true if the whole file content is correct.
*/
bool	has_valid_content(t_list *lst)
{
	t_list	*tmp;
	int		occurences[3];

	fill_with_zeros(occurences);
	tmp = lst;
	while (tmp)
	{
		if (check_element(tmp->content) == false)
			return (false);
		if (ft_strncmp(((char **)tmp->content)[0], "A", 2) == 0)
			occurences[0]++;
		if (ft_strncmp(((char **)tmp->content)[0], "C", 2) == 0)
			occurences[1]++;
		if (ft_strncmp(((char **)tmp->content)[0], "L", 2) == 0)
			occurences[2]++;
		tmp = tmp->next;
	}
	return (check_minimum_occurences(occurences));
}
