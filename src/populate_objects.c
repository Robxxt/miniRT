/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 07:13:32 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 10:38:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"
#include "../includes/api.h"

void	populate_pl(t_image *image, char **node_content)
{
	int	i;

	i = image->amount.pl;
	if (i < 9)
	{
		image->amount.pl++;
		image->plane[i].exists = true;
		read_float_list(image->plane[i].pos, node_content[1]);
		read_float_list(image->plane[i].nv, node_content[2]);
		read_int_list(image->plane[i].rgb, node_content[3]);
	}
}

void	populate_cy(t_image *image, char **node_content)
{
	float	h;
	float	d;
	int	i;

	i = image->amount.cy;
	if (i < 9)
	{
		image->amount.cy++;
		image->cylinder[i].exists = true;
		d = ft_atof(node_content[3]);
		image->cylinder[i].d = d;
		h = ft_atof(node_content[4]);
		image->cylinder[i].h = h;
		read_float_list(image->cylinder[i].pos, node_content[1]);
		read_float_list(image->cylinder[i].nv, node_content[2]);
		read_int_list(image->cylinder[i].rgb, node_content[5]);
	}
}

void	populate_sp(t_image *image, char **node_content)
{
	float	d;
	int	i;

	i = image->amount.sp;
	if (i < 9)
	{
		image->amount.sp++;
		image->sphere[i].exists = true;
		read_float_list(image->sphere[i].pos, node_content[1]);
		d = ft_atof(node_content[2]);
		image->sphere[i].d = d;
		read_int_list(image->sphere[i].rgb, node_content[3]);
	}
}

void	populate_cb(t_image *image, char **node_content)
{
	float	flt[3];
	int		rgb[3];
	int		i;

	i = image->amount.cb;
	if (i < 9)
	{
		image->amount.cb++;
		image->cube[i].exists = true;
		read_float_list(flt, node_content[1]);
		float_to_vector(flt, &(image->cube[i].pos));
		read_float_list(flt, node_content[2]);
		float_to_vector(flt, &(image->cube[i].nv1));
		read_float_list(flt, node_content[3]);
		float_to_vector(flt, &(image->cube[i].nv2));
		image->cube[i].size = atof(node_content[4]);
		read_int_list(rgb, node_content[5]);
		rgb_to_color(rgb, &(image->cube[i].rgb));
		image->cube[i].texture = 'n';
		i++;
	}
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
	else if (node_type == 7)
		populate_cb(image, node_content);
}
