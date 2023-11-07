/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:28:57 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 07:45:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Reads one line from fd and trimms it.
*/
char	*get_trimmed_line(int fd)
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

	result = NULL;
	i = 0;
	tmp = get_trimmed_line(fd);
	while(tmp)
	{
		char	**sp = ft_split(tmp, ' ');
		
		if (sp[0])
		{
			node = ft_lstnew(sp);
			if (i == 0)
				result = node;
			else
				ft_lstadd_back(&result, node);
		}
		else
		{
			free_split(sp);
		}
		free(tmp);
		tmp = get_trimmed_line(fd);
		i++;
	}
	free(tmp);
	return result;
}

int	main(int argc, char **argv)
{
	parsing_tests();

	if (argc != 2)
	{
		ft_putstr_fd("Missing the image file!\n", STDERR_FILENO);
		return (1);
	}
	int	fd;

	fd = open(argv[1], O_RDONLY);
	t_list *file_content = get_file_content(fd);
	print_lst(file_content);
	ft_lstclear(&file_content);
	free(file_content);
	return (0);
}
