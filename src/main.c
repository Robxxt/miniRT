/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:28:57 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 14:53:53 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Checks that the program has received a valid argument
containing the filename with the map.
*/
bool	init_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("ERROR: Missing the image file!\n", STDERR_FILENO);
		return (false);
	}
	if (is_valid_file(argv[1]) == false)
	{
		ft_putstr_fd("ERROR: Invalid File!\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}

/*
Goes through the link list freeing each node content.
After frees the list itself.
*/
void	clear_lst(t_list *lst)
{
	ft_lstclear(&lst);
	free(lst);
}

int	main(int argc, char **argv)
{
	parsing_tests();
	t_image	*image;

	if (init_check(argc, argv) == false)
		return (1);
	image = parser(argv);
	printf("%p\n", image);
	return (0);
}
