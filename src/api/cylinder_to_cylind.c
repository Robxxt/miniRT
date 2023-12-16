/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_to_cylind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:17:40 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 18:19:32 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_sphere and t_sp
and fills p2 with the values from p1.
*/
void	cylinder_to_cylind(t_cylinder p1, t_cylind* p2)
{
	p2->exists = p1.exists;
	p2->height = p1.h;
	p2->radii = p1.d / 2;
	float_to_vector(p1.pos, &(p2->pos));
	float_to_vector(p1.nv, &(p2->nv));
	rgb_to_color(p1.rgb, &(p2->rgb));
	p2->texture = 'n';
}
