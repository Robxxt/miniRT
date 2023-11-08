/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:31:02 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 15:29:24 by rdragan          ###   ########.fr       */
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
Checks that A, C, L are uniq in the file. If they
are uniq returns true, otherwise false.
*/
bool	check_uniq_values(int *occurences)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (occurences[i] != 1)
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
	int	occurences[3];

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
	return (check_uniq_values(occurences));
}
