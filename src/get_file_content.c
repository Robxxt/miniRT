/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:29:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:23:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Reads one line from fd and trimms it.
*/
static char	*get_trimmed_line(int fd)
{
	char	*tmp;
	char	*res;

	tmp = get_next_line(fd);
	res = ft_strtrim(tmp, "\n");
	free(tmp);
	return (res);
}

/*
Makes a list with all the lines.
Each line is a node in the list.
Each node has the splitted content of the line.
Returns NULL if any validation fails.
*/
t_list	*get_file_content(int fd)
{
	t_list	*result;
	t_list	*node;
	char	*tmp;
	int		i;
	char	**sp;

	result = NULL;
	i = 0;
	tmp = get_trimmed_line(fd);
	while (tmp)
	{
		sp = ft_split(tmp, ' ');
		if (sp[0])
		{
			node = ft_lstnew(sp);
			if (i == 0)
				result = node;
			else
				ft_lstadd_back(&result, node);
		}
		else
			free_split(sp);
		free(tmp);
		tmp = get_trimmed_line(fd);
		i++;
	}
	free(tmp);
	return (result);
}
