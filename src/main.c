/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:28:57 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/09 08:22:36 by rdragan          ###   ########.fr       */
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

//  ONLY FOR DEBUGGING
void	print_rgb(int *lst)
{
	for (int i = 0; i < 3; i++)
		printf(" %d", lst[i]);
	printf("\n");
}

//  ONLY FOR DEBUGGING
void	print_float_lst(float *lst)
{
	for (int i = 0; i < 3; i++)
		printf(" %f", lst[i]);
	printf("\n");
}

//  ONLY FOR DEBUGGING
void	print_img_info(t_image *image)
{
	if (image)
	{
		printf("Ambient:\n");
		printf("> r: %f\n", image->ambient.r);
		print_rgb(image->ambient.rgb);

		printf("Camara:\n");
		printf("> fv: %d\n", image->camara.fv);
		printf("Pos:");
		print_float_lst(image->camara.pos);
		printf("nv:");
		print_float_lst(image->camara.nv);

		printf("Light:\n");
		printf("Pos:");
		print_float_lst(image->light.pos);
		printf("> lb: %f\n", image->light.lb);
		print_rgb(image->light.rgb);

		printf("Sp:\n");
		printf("exists: %d\n", image->sphere.exists);
		if (image->sphere.exists)
		{
			printf("Pos:");
			print_float_lst(image->sphere.pos);
			printf("> d: %f\n", image->sphere.d);
			print_rgb(image->sphere.rgb);
		}
		printf("Pl:\n");
		printf("exists: %d\n", image->plane.exists);
		if (image->plane.exists)
		{
			printf("Pos:");
			print_float_lst(image->plane.pos);
			printf("Nv:");
			print_float_lst(image->plane.nv);
			print_rgb(image->plane.rgb);
		}
		printf("Cy:\n");
		printf("exists: %d\n", image->cylinder.exists);
		if (image->cylinder.exists)
		{
			printf("Pos:");
			print_float_lst(image->cylinder.pos);
			printf("Nv:");
			print_float_lst(image->cylinder.nv);
			printf("diameter: %f\nheight: %f\n", image->cylinder.d, image->cylinder.h);
			print_rgb(image->cylinder.rgb);
		}
	}
}

int	main(int argc, char **argv)
{
	parsing_tests();
	t_image	*image;

	if (init_check(argc, argv) == false)
		return (1);
	image = parser(argv);
	print_img_info(image);
	if (image != NULL)
		free(image);
	return (0);
}
