/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:21:41 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/12 00:10:48 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_surface	trace_sp(t_sp *sp, t_ray *ray)
{
	float		a;
	float		b;
	float		c;
	float		d;
	t_surface	re;

	re.pos.x = NAN;
	if (sp->exists == false)
		return (re);
	re.pos = v_minus(&ray->pos, &sp->pos);
	b = 2.0f * dot_product(&ray->nv, &re.pos);
	c = distance2(&ray->pos, &sp->pos) - sp->radii * sp->radii;
	a = module2(&ray->nv);
	d = delta()
}
