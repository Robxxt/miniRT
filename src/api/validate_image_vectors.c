/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_image_vectors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:28:12 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 12:09:10 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

bool	check_vector(float *vec)
{
	t_vector	res;

	float_to_vector(vec, &res);
	if (module2(&res) < 0.9999 || module2(&res) > 1.0001)
		return (false);
	return (true);
}

bool	check_vector2(t_vector *vec)
{
	if (module2(vec) < 0.9999 || module2(vec) > 1.0001)
		return (false);
	return (true);
}

bool	image_has_valid_vectors(t_image *img)
{
	if (img->cylinder->exists && !check_vector(img->cylinder->nv))
		return (false);
	if (!check_vector(img->camara.nv))
		return (false);
	if (img->plane->exists && !check_vector(img->plane->nv))
		return (false);
	if (img->cylinder->exists && !check_vector(img->cylinder->nv))
		return (false);
	if (img->cube->exists && (!check_vector2(&(img->cube->nv1))
			|| !check_vector2(&(img->cube->nv2))))
	{
		return (false);
	}
	return (true);
}
