/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/17 15:23:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Transfer the objects from t_image to t_space.
*/
void	transfer_objects(t_image p1, t_space* p2)
{
	int	i;
	
	i = -1;
	while (++i < p2->amount.pl)
		plane_to_panel(p1.plane[i], &(p2->pl[i]));
	i = -1;
	while (++i < p2->amount.cy)
		cylinder_to_cylind(p1.cylinder[i], &(p2->cylind[i]));
	i = -1;
	while (++i < p2->amount.sp)
		sphere_to_sp(p1.sphere[i], &(p2->sp[i]));
	i = -1;
	while (++i < p2->amount.cb)
		p2->cub[i] = p1.cube[i];
}

/*
Handles the differences between t_image and t_space
and fills p2 with the values from p1.
*/
void	image_to_space(t_image p1, t_space* p2)
{
	int	i;

	p2->amount = p1.amount;
	ambient_to_ambt(p1.ambient, &(p2->ambient));
	camara_to_cmr(p1.camara, &(p2->cmr));
	i = 0;
	while (i < p1.amount.lit)
	{
		light_to_lit(p1.light[i], &(p2->lit[i]));
		i++;
	}
	p2->lit[i].pos.x = NAN;
	transfer_objects(p1, p2);
}
