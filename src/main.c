/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:28:57 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 13:26:17 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"
#include "../includes/api.h"

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

// int	main(int argc, char **argv)
// {
// 	parsing_tests();
// 	api_tests();
// 	t_image	*image;
// 	t_space	space;

// 	image = parser(argv);
// 	image_to_space(*image, &(space));
// 	print_space(space);
// 	if (image != NULL)
// 		free(image);
// 	return (0);
// }

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	esc_exit(int button, t_vars *vars)
{
	if (button == 53)
		close_window(vars);
	return (0);
}

void	ray_tracing(t_space *space, t_vars *vars)
{
	t_pixel	pix;
	t_ray	ray;
	t_color color;

	pix.x = 0;
	pix.y = 0;
	while (pix.x < SCREEN_X)
	{
		pix.y = 0;
		while (pix.y < SCREEN_Y)
		{
			ray = camera_ray(&space->cmr, &pix);
			// printf("[%f,%f,%f]",ray.nv.x, ray.nv.y, ray.nv.z);
			color =	trace_rays(space, ray, 0);
			// if (color.bright)
			// 	printf("%u|",get_color(&color));
			// 	printf("[%u]", color.bright);
			
			paint_pixel(vars, pix, get_color(&color));
			// printf("[%sd,%d]\n",pix.x, pix.y);
			pix.y++;
		}
		pix.x++;
	}
}

void	all(t_vars *vars, void *mlx, void *mlx_win, t_image* image)
{
	t_space space;

	ft_bzero(&space, sizeof(space));
	image_to_space(*image, &space);
	print_space(space);
	ray_tracing(&space, vars);

	mlx_put_image_to_window(mlx, mlx_win, vars->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_image	*image;
	
	if (init_check(argc, argv) == false)
		return (1);
	image = parser(argv);
	if (image == NULL)
		return (1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_X, SCREEN_Y, "miniRT");
	vars.img = mlx_new_image(vars.mlx, SCREEN_X, SCREEN_Y);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, &vars.l_len, &vars.edn);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	all(&vars, vars.mlx, vars.win, image);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_key_hook(vars.win, esc_exit, &vars);
	mlx_loop(vars.mlx);
	if (image != NULL)
		free(image);
	return (0);
}
