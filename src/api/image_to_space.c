/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 21:00:13 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_image and t_space
and fills p2 with the values from p1.
*/
void	image_to_space(t_image p1, t_space* p2)
{
	ambient_to_ambt(p1.ambient, &(p2->ambient));
	camara_to_cmr(p1.camara, &(p2->cmr));
	light_to_lit(p1.light, &(p2->lit[0]));
	p2->lit[1].pos.x = NAN;
	sphere_to_sp(p1.sphere, &(p2->sp[0]));
	plane_to_panel(p1.plane, &(p2->pl[0]));
	cylinder_to_cylind(p1.cylinder, &(p2->cylind[0]));
}
