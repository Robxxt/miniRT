/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_context_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:54:25 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 16:30:00 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	populate_a(t_image *image, char **node_content)
{
	float	r;

	r = ft_atof(node_content[1]);
	image->ambient.r = r;
	read_int_list(image->ambient.rgb, node_content[2]);
	printf("Populating a...\n");
}

void	populate_c(t_image *image, char **node_content)
{
	float	fv;

	fv = ft_atof(node_content[3]);
	image->camara.fv = fv;
	read_float_list(image->camara.pos, node_content[1]);
	read_float_list(image->camara.nv, node_content[2]);
	printf("Populating c...\n");
}

void	populate_l(t_image *image, char **node_content)
{
	(void)image;
	(void)node_content;
	printf("Populating l...\n");
}

/*
Populate elements basically reads the content of a node into
it's specific atribute in the image struct.
*/
void	populate_context_elements(t_image *image, char **node_content, int node_type)
{
	if (node_type == 1)
		populate_a(image, node_content);
	else if (node_type == 2)
		populate_c(image, node_content);
	else
		populate_l(image, node_content);
}
