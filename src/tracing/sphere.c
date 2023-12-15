/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:21:41 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/15 00:50:09 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	min_root(float a, float b, float c)
{
	float	root_m;
	float	root_p;

	root_m = root_minus(a, b, c);
	if (root_m >= 0.0f)
		return (root_m);
	root_p = root_plus(a, b, c);
	return (root_p);
}

t_color	check_board(t_vector *nv)
{
	int		zz;
	int		ag;
	t_color	re;

	ft_bzero(&re, sizeof(re));
	re.bright = 255U;
	zz = roundf(asinf(nv->z) * 4.1f);
	ag = roundf(atan2f(nv->x, nv->y) * 4.1f);
	if ((zz + ag) % 2)
	{
		re.r = 255U;
		re.g = 255U;
		re.b = 255U;
	}
	return (re);
}

t_color	bump(t_vector *nv)
{
	int		zz;
	int		ag;
	t_color	re;

	ft_bzero(&re, sizeof(re));
	re.bright = 255U;
	zz = roundf(asinf(nv->z) * 4.1f);
	ag = roundf(atan2f(nv->x, nv->y) * 4.1f);
	if ((zz + ag) % 2)
	{
		re.r = 255U;
		re.g = 255U;
		re.b = 255U;
	}
	return (re);
}

t_color	set_texture(t_sp *sp, t_vector *nv, char t)
{
	t_color	re;

	re = sp->rgb;
	if (t == 'n' || t == 'p')
		return (sp->rgb);
	if (t == 'c')
		return (check_board(nv));
	if (t == 'b')
		return (bump(nv));
	return (re);
}

t_surface	trace_sp(t_sp *sp, t_ray *ray)
{
	float		a;
	float		b;
	float		c;
	float		lambda;
	t_surface	re;

	re.pos.x = NAN;
	if (sp->exists == false)
		return (re);
	re.pos = v_minus(&ray->pos, &sp->pos);
	b = 2.0f * dot_product(&ray->nv, &re.pos);
	c = distance2(&ray->pos, &sp->pos) - sp->radii * sp->radii;
	a = module2(&ray->nv);
	re.pos.x = NAN;
	if (delta(a, b, c) < 0.0f)
		return (re);
	lambda = min_root(a, b, c);
	if (lambda < 0.0f)
		return (re);
	re.pos = v_product(&ray->nv, lambda);
	re.pos = v_plus(&ray->pos, &re.pos);
	re.nv = normized(v_minus(&re.pos, &sp->pos));
	re.texture = sp->texture;
	re.rgb = set_texture(sp, &re.nv, re.texture);
	return (re);
}
