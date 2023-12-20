/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:40:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 12:57:23 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Returns the type of the node.
1: A
2: C
3: L
4: pl
5: sp
6: cy
7: cb
-1: failed
*/
int	get_node_type(t_list *node)
{
	if (ft_strncmp("A", ((char **)node->content)[0], 2) == 0)
		return (1);
	if (ft_strncmp("C", ((char **)node->content)[0], 2) == 0)
		return (2);
	if (ft_strncmp("L", ((char **)node->content)[0], 2) == 0)
		return (3);
	if (ft_strncmp("pl", ((char **)node->content)[0], 3) == 0)
		return (4);
	if (ft_strncmp("sp", ((char **)node->content)[0], 3) == 0)
		return (5);
	if (ft_strncmp("cy", ((char **)node->content)[0], 3) == 0)
		return (6);
	if (ft_strncmp("cb", ((char **)node->content)[0], 3) == 0)
		return (7);
	return (-1);
}

/*
Check what type of element is the node and populates
it in the place where must be.
*/
void	populate_image(t_image *image, t_list *node)
{
	int		node_type;
	char	**node_content;

	node_type = get_node_type(node);
	node_content = node->content;
	if (node_type == -1)
		return ;
	else if (node_type <= 3)
		populate_context_elements(image, node_content, node_type);
	else
		populate_objects(image, node_content, node_type);
}

t_image	*get_image(t_list *lst)
{
	t_image	*image;
	t_list	*tmp;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	init_amount(&(image->amount));
	init_objects_exist_to_false(image);
	tmp = lst;
	while (tmp)
	{
		populate_image(image, tmp);
		tmp = tmp->next;
	}
	return (image);
}

/*
Receives a list with the file content and returns
the parsed image ready for rendering.
*/
t_image	*parser(char **argv)
{
	int		fd;
	t_image	*image;
	t_list	*file_content;

	fd = open(argv[1], O_RDONLY);
	file_content = get_file_content(fd);
	if (!has_valid_content(file_content))
	{
		ft_putstr_fd("ERROR: Invalid File Content!\n", STDERR_FILENO);
		clear_lst(file_content);
		return (NULL);
	}
	image = get_image(file_content);
	clear_lst(file_content);
	return (image);
}
