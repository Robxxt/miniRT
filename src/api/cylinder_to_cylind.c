/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_to_cylind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:17:40 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 13:07:50 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_cylinder and t_cylind
and fills p2 with the values from p1.
*/
void	cylinder_to_cylind(t_cylinder p1, t_cylind *p2)
{
	p2->exists = p1.exists;
	p2->height = p1.h;
	p2->radii = p1.d / 2;
	float_to_vector(p1.pos, &(p2->pos));
	float_to_vector(p1.nv, &(p2->nv));
	rgb_to_color(p1.rgb, &(p2->rgb));
	p2->texture = p1.texture;
	set_cyd(p2);
}
