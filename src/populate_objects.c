/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 07:13:32 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/27 15:20:13 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	populate_pl(t_image *image, char **node_content)
{
	image->plane.exists = true;
	read_float_list(image->plane.pos, node_content[1]);
	read_float_list(image->plane.nv, node_content[2]);
	read_int_list(image->plane.rgb, node_content[3]);
}

void	populate_cy(t_image *image, char **node_content)
{
	float	h;
	float	d;

	image->cylinder.exists = true;
	d = ft_atof(node_content[3]);
	image->cylinder.d = d;
	h = ft_atof(node_content[4]);
	image->cylinder.h = h;
	read_float_list(image->cylinder.pos, node_content[1]);
	read_float_list(image->cylinder.nv, node_content[2]);
	read_int_list(image->cylinder.rgb, node_content[5]);
}

void	populate_cb(t_image *image, char **node_content)
{
	image->cube.exists = true;
	read_float_list(image->cube.pos, node_content[1]);
	read_float_list(image->cube.nv, node_content[2]);
	read_int_list(image->cube.rgb, node_content[3]);
}

void	populate_sp(t_image *image, char **node_content)
{
	float	d;

	image->sphere.exists = true;
	read_float_list(image->sphere.pos, node_content[1]);
	d = ft_atof(node_content[2]);
	image->sphere.d = d;
	read_int_list(image->sphere.rgb, node_content[3]);
	
}

/*
Populate elements basically reads the content of a node into
it's specific atribute in the image struct.
*/
void	populate_objects(t_image *image, char **node_content, int node_type)
{
	if (node_type == 4)
		populate_pl(image, node_content);
	else if (node_type == 5)
		populate_sp(image, node_content);
	else if (node_type == 6)
		populate_cy(image, node_content);
	else
		populate_cb(image, node_content);
}
