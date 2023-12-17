/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/17 12:18:24 by rdragan          ###   ########.fr       */
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
	p2->amount = p1.amount;
	printf("lit: %d\n", p2->amount.lit);
	printf("cy: %d\n", p2->amount.cy);
	printf("pl: %d\n", p2->amount.pl);
	printf("sp: %d\n", p2->amount.sp);
	ambient_to_ambt(p1.ambient, &(p2->ambient));
	camara_to_cmr(p1.camara, &(p2->cmr));
	light_to_lit(p1.light[0], &(p2->lit[0]));
	p2->lit[1].pos.x = NAN;
	sphere_to_sp(p1.sphere[0], &(p2->sp[0]));
	plane_to_panel(p1.plane[0], &(p2->pl[0]));
	cylinder_to_cylind(p1.cylinder[0], &(p2->cylind[0]));
}
