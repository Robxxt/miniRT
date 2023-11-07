/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:28:57 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 08:45:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	start_program(t_list *lst)
{
	printf("MINI RT LOADING...\n");
	(void)lst;
	// print_lst(lst);
}

int	main(int argc, char **argv)
{
	int	fd;
	parsing_tests();

	if (argc != 2)
	{
		ft_putstr_fd("ERROR: Missing the image file!\n", STDERR_FILENO);
		return (1);
	}
	if (is_valid_file(argv[1]) == false)
	{
		ft_putstr_fd("ERROR: Invalid File!\n", STDERR_FILENO);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	t_list *file_content = get_file_content(fd);
	if (has_valid_content(file_content))
	{
		start_program(file_content);
	}
	else
	{
		ft_putstr_fd("ERROR: Invalid File Content!\n", STDERR_FILENO);
		return (1);
	}
	ft_lstclear(&file_content);
	free(file_content);
	return (0);
}
