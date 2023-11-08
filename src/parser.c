/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:40:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 14:52:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"



/*
Receives a list with the file content and returns the parsed
image ready for rendering.
*/
t_image	*parser(char **argv)
{
	int	fd;
	// t_image	*image;

	fd = open(argv[1], O_RDONLY);
	t_list *file_content = get_file_content(fd);
	if (!has_valid_content(file_content))
	{
		ft_putstr_fd("ERROR: Invalid File Content!\n", STDERR_FILENO);
		clear_lst(file_content);
		return (NULL);
	}
	printf("Staring programm...\n");
	clear_lst(file_content);
	return (NULL);
}
