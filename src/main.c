/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:28:57 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 19:41:40 by rdragan          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	parsing_tests();
	api_tests();
	t_image	*image;
	t_space	space;

	if (init_check(argc, argv) == false)
		return (1);
	image = parser(argv);
	image_to_space(*image, &(space));
	print_space(space);
	if (image != NULL)
		free(image);
	return (0);
}

// int	close_window(t_vars *vars)
// {
// 	mlx_destroy_image(vars->mlx, vars->img);
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// 	return (0);
// }

// int	esc_exit(int button, t_vars *vars)
// {
// 	if (button == 53)
// 		close_window(vars);
// 	return (0);
// }

// void	ray_tracing(t_space *space, t_vars *vars)
// {
// 	t_pixel	pix;
// 	t_ray	ray;
// 	t_color color;

// 	pix.x = 0;
// 	pix.y = 0;
// 	while (pix.x < SCREEN_X)
// 	{
// 		pix.y = 0;
// 		while (pix.y < SCREEN_Y)
// 		{
// 			ray = camera_ray(&space->cmr, &pix);
// 			// printf("[%f,%f,%f]",ray.nv.x, ray.nv.y, ray.nv.z);
// 			color =	trace_rays(space, ray, 0);
// 			// if (color.bright)
// 			// 	printf("%u|",get_color(&color));
// 			// 	printf("[%u]", color.bright);
			
// 			paint_pixel(vars, pix, get_color(&color));
// 			// printf("[%sd,%d]\n",pix.x, pix.y);
// 			pix.y++;
// 		}
// 		pix.x++;
// 	}
// }

// /*
// ** cube sides: up down, left right, front back
// **		index: 1  6     2    5      3     4
// */

// void	set_cube(t_cub *cub)
// {
// 	t_vector	tmp;
// 	int			i;

// 	cub->side[3].nv = cub->nv1;
// 	// tmp = v_product(&cub->side[3].nv, 0.5f * cub->size);
// 	// cub->side[3].pos = v_plus(&cub->pos, &tmp);
// 	cub->side[4].nv = v_product(&cub->nv1, -1.0f);
// 	cub->side[5].nv = cub->nv2;
// 	cub->side[2].nv = v_product(&cub->nv2, -1.0f);
// 	cub->side[1].nv = cross_product(&cub->nv1, &cub->nv2);
// 	cub->side[6].nv = v_product(&cub->side[1].nv, -1.0f);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		tmp = v_product(&cub->side[i].nv, 0.5f * cub->size);
// 		cub->side[i].pos = v_plus(&cub->pos, &tmp);
// 		// printf("P[%f,%f,%f]\n",cub->side[i].pos.x,cub->side[i].pos.y,cub->side[i].pos.z);
// 		// printf("N[%f,%f,%f]\n",cub->side[i].nv.x,cub->side[i].nv.y,cub->side[i].nv.z);
// 		i++;
// 	}
// }


// void	set_cyd(t_cylind *cyd)
// {
// 	t_vector	tmp;

// 	cyd->up.nv = cyd->nv;
// 	cyd->down.nv = v_product(&cyd->nv, -1.0f);
// 	tmp = v_product(&cyd->nv, cyd->height * 0.5f);
// 	cyd->up.pos = v_plus(&cyd->pos, &tmp);
// 	cyd->down.pos = v_minus(&cyd->pos, &tmp);
// 	cyd->up.radii = cyd->radii;
// 	cyd->down.radii = cyd->radii;
// }

// void	all(t_vars *vars, void *mlx, void *mlx_win)
// {
// 	t_space space;
// 	// t_ambt abt;
// 	// t_cmr cmr;
// 	// t_cub cub;
// 	// t_panel pl;
// 	// t_sp sp;
// 	// t_lit lit;
// 	// t_cylind cyd;
// 	space.ambient.rgb.r = 255U;
// 	space.ambient.rgb.g = 255U;
// 	space.ambient.rgb.b = 255U;
// 	space.ambient.rgb.bright = 31U;

// 	space.cmr.fv = 90;
// 	space.cmr.nv.z = -0.70710678f;
// 	space.cmr.nv.x = -0.70710678f;
// 	space.cmr.nv.y = 0.0f;
// 	space.cmr.pos.z = 10.0f;
// 	space.cmr.pos.x = 10.0f;
// 	space.cmr.pos.y = 0.0f;

// 	// space.cmr.fv = 90;
// 	// space.cmr.nv.z = -1.0f;
// 	// space.cmr.nv.x = 0.0f;
// 	// space.cmr.nv.y = 0.0f;
// 	// space.cmr.pos.z = 10.0f;
// 	// space.cmr.pos.x = 0.0f;
// 	// space.cmr.pos.y = 0.0f;

// 	space.cub.exists = true;
// 	space.cub.pos.x = -1.0f;
// 	space.cub.pos.y = 1.0f;
// 	space.cub.pos.z = 1.0f;
// 	space.cub.nv1.x = 1.0f;
// 	space.cub.nv1.y = 0.0f;
// 	space.cub.nv1.z = 0.0f;
// 	space.cub.nv2.x = 0.0f;
// 	space.cub.nv2.y = 0.70710678f;
// 	space.cub.nv2.z = 0.70710678f;
// 	space.cub.size = 2.0f;
// 	space.cub.texture = 'p';
// 	space.cub.rgb.r = 255;
// 	space.cub.rgb.g = 0;
// 	space.cub.rgb.b = 0;
// 	space.cub.rgb.bright = 255;
// 	set_cube(&space.cub);


// 	// space.cub.exists = true;
// 	// space.cub.pos.x = 0.0f;
// 	// space.cub.pos.y = 0.0f;
// 	// space.cub.pos.z = 5.0f;
// 	// space.cub.nv1.x = 1.0f;
// 	// space.cub.nv1.y = 0.0f;
// 	// space.cub.nv1.z = 0.0f;
// 	// space.cub.nv2.x = 0.0f;
// 	// space.cub.nv2.y = 1.0f;
// 	// space.cub.nv2.z = 0.0f;
// 	// space.cub.size = 2.0f;
// 	// space.cub.texture = 'n';
// 	// space.cub.rgb.r = 255;
// 	// space.cub.rgb.g = 0;
// 	// space.cub.rgb.b = 0;
// 	// space.cub.rgb.bright = 255;
// 	// set_cube(&space.cub);

// 	space.sp.exists = true;
// 	space.sp.pos.x = 1.0f;
// 	space.sp.pos.y = 1.5f;
// 	space.sp.pos.z = 0.4f;
// 	space.sp.rgb.r = 0U;
// 	space.sp.rgb.g = 255U;
// 	space.sp.rgb.b = 255U;
// 	space.sp.rgb.bright = 255U;
// 	space.sp.radii = 1.0f;
// 	space.sp.texture = 'n';


// 	space.cylind.exists = true;
// 	space.cylind.pos.x = -3.0f;
// 	space.cylind.pos.y = -2.0f;
// 	space.cylind.pos.z = 1.0f;
// 	space.cylind.nv.x = 0.0f;
// 	space.cylind.nv.y = 0.0f;
// 	space.cylind.nv.z = 1.0f;
// 	space.cylind.texture = 'n';
// 	space.cylind.radii = 1.0f;
// 	space.cylind.rgb.r = 255U;
// 	space.cylind.rgb.g = 0U;
// 	space.cylind.rgb.b = 255U;
// 	space.cylind.rgb.bright = 255U;
// 	space.cylind.height = 2.0f;
// 	set_cyd(&space.cylind);


// 	space.pl.exists = true;
// 	space.pl.nv.x = 0.0f;
// 	space.pl.nv.y = 0.0f;
// 	space.pl.nv.z = 1.0f;
// 	space.pl.pos.x = 0.0f;
// 	space.pl.pos.y = 0.0f;
// 	space.pl.pos.z = 0.0f;
// 	space.pl.rgb.r = 255U;
// 	space.pl.rgb.g = 255U;
// 	space.pl.rgb.b = 255U;
// 	space.pl.rgb.bright = 255U;
// 	space.pl.texture = 'n';

// 	// space.lit[0].pos.x = 3.0f;
// 	// space.lit[0].pos.y = 0.0f;
// 	// space.lit[0].pos.z = 3.0f;
// 	// space.lit[0].rgb.r = 255U;
// 	// space.lit[0].rgb.g = 255U;
// 	// space.lit[0].rgb.b = 255U;
// 	// space.lit[0].rgb.bright = 255U;

// 	space.lit[0].pos.x = 6.0f;
// 	space.lit[0].pos.y = 10.0f;
// 	space.lit[0].pos.z = 10.0f;
// 	space.lit[0].rgb.r = 255U;
// 	space.lit[0].rgb.g = 255U;
// 	space.lit[0].rgb.b = 255U;
// 	space.lit[0].rgb.bright = 255U;

// 	space.lit[1].pos.x = 6.0f;
// 	space.lit[1].pos.y = -10.0f;
// 	space.lit[1].pos.z = 10.0f;
// 	space.lit[1].rgb.r = 255U;
// 	space.lit[1].rgb.g = 255U;
// 	space.lit[1].rgb.b = 255U;
// 	space.lit[1].rgb.bright = 255U;
// 	// printf("seg\n");

// 	space.lit[2].pos.x = NAN;
// 	space.lit[2].pos.y = 0.0f;
// 	space.lit[2].pos.z = 1.0f;
// 	space.lit[2].rgb.r = 216U;
// 	space.lit[2].rgb.g = 255U;
// 	space.lit[2].rgb.b = 255U;
// 	space.lit[2].rgb.bright = 255U;

// 	space.lit[3].pos.x = NAN;

// 	ray_tracing(&space, vars);

// 	mlx_put_image_to_window(mlx, mlx_win, vars->img, 0, 0);
// }

// int	main()
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, SCREEN_X, SCREEN_Y, "miniRT");
// 	vars.img = mlx_new_image(vars.mlx, SCREEN_X, SCREEN_Y);
// 	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, &vars.l_len, &vars.edn);
// 	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
// 	all(&vars, vars.mlx, vars.win);
// 	mlx_hook(vars.win, 17, 0, close_window, &vars);
// 	// mlx_mouse_hook(vars.win, zoom, &vars);
// 	mlx_key_hook(vars.win, esc_exit, &vars);
// 	mlx_loop(vars.mlx);
// 	return (0);
// }
