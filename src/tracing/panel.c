/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:24:00 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/11 22:44:33 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_surface	trace_pl(t_panel *pl, t_ray *ray)
{
	t_surface	re;
	float		lambda;

	re.pos.x = NAN;
	if (pl->exists == false)
		return (re);
	re.texture = pl->texture;
	lambda = dot_product(&pl->pos, &pl->nv) - dot_product(&ray->pos, &pl->nv);
	lambda = lambda / dot_product(&ray->nv, &pl->nv);
	if (lambda < 0.0f)
		return (re);
	re.pos = v_product(&ray->nv, lambda);
	re.pos = v_plus(&ray->pos, &re.pos);
	re.rgb = pl->rgb;
	re.nv = pl->nv;
	return (re);
}
