/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:08:17 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/20 12:17:25 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_surface	trace_up(t_circle *cir, t_ray *ray)
{
	t_surface	re;
	float		lambda;

	re.pos.x = NAN;
	lambda = dot_product(&cir->pos, &cir->nv);
	lambda = lambda - dot_product(&ray->pos, &cir->nv);
	lambda = lambda / dot_product(&ray->nv, &cir->nv);
	if (lambda < 0.0f)
		return (re);
	re.pos = v_product(&ray->nv, lambda);
	re.pos = v_plus(&ray->pos, &re.pos);
	if (distance2(&re.pos, &cir->pos) > cir->radii * cir->radii)
	{
		re.pos.x = NAN;
		return (re);
	}
	re.nv = cir->nv;
	return (re);
}

t_surface	trace_down(t_circle *cir, t_ray *ray)
{
	t_surface	re;
	float		lambda;

	re.pos.x = NAN;
	lambda = dot_product(&cir->pos, &cir->nv);
	lambda = lambda - dot_product(&ray->pos, &cir->nv);
	lambda = lambda / dot_product(&ray->nv, &cir->nv);
	if (lambda < 0.0f)
		return (re);
	re.pos = v_product(&ray->nv, lambda);
	re.pos = v_plus(&ray->pos, &re.pos);
	if (distance2(&re.pos, &cir->pos) > cir->radii * cir->radii)
	{
		re.pos.x = NAN;
		return (re);
	}
	re.nv = cir->nv;
	return (re);
}

t_surface	get_solution(t_cylind *cylind, t_ray *ray, float *a)
{
	t_surface	re;
	t_surface	tmp;
	float		lambda;
	t_vector	v;

	re.pos.x = NAN;
	if (delta(a[0], a[1], a[2]) < 0.0f)
		return (re);
	lambda = min_root(a[0], a[1], a[2]);
	if (lambda < 0.0f)
		return (re);
	tmp.pos = v_product(&ray->nv, lambda);
	tmp.pos = v_plus(&ray->pos, &tmp.pos);
	v = v_minus(&cylind->up.pos, &tmp.pos);
	if (dot_product(&v, &cylind->up.nv) < 0.0f)
		return (re);
	v = v_minus(&cylind->down.pos, &tmp.pos);
	if (dot_product(&v, &cylind->down.nv) < 0.0f)
		return (re);
	tmp.nv.x = lambda;
	return (tmp);
}

t_surface	trace_cydside(t_cylind *cylind, t_ray *ray)
{
	float		a[3];
	t_vector	t1;
	t_vector	t2;
	t_surface	re;

	a[0] = dot_product(&ray->nv, &cylind->nv);
	t1 = v_product(&cylind->nv, a[0]);
	t1 = v_minus(&t1, &ray->nv);
	t2 = v_minus(&ray->pos, &cylind->pos);
	a[0] = dot_product(&t2, &cylind->nv);
	t2 = v_product(&cylind->nv, a[0]);
	t2 = v_minus(&t2, &ray->pos);
	t2 = v_plus(&t2, &cylind->pos);
	a[0] = dot_product(&t1, &t1);
	a[1] = 2.0f * dot_product(&t1, &t2);
	a[2] = dot_product(&t2, &t2) - cylind->radii * cylind->radii;
	re = get_solution(cylind, ray, a);
	if (!isnan(re.pos.x))
	{
		t1 = v_product(&t1, re.nv.x);
		t1 = v_plus(&t1, &t2);
		re.nv = normized(v_product(&t1, -1.0f));
	}
	return (re);
}

t_surface	trace_cyl(t_cylind *cylind, t_ray *ray)
{
	t_surface	re;
	t_surface	tmp[3];
	float		dis;
	int			i;

	dis = 3.4028235E38f;
	re.pos.x = NAN;
	if (cylind->exists == false)
		return (re);
	tmp[0] = trace_up(&cylind->up, ray);
	tmp[1] = trace_down(&cylind->down, ray);
	tmp[2] = trace_cydside(cylind, ray);
	i = -1;
	while (++i < 3)
	{
		if (!isnan(tmp[i].pos.x) && distance2(&tmp[i].pos, &ray->pos) < dis)
		{
			re = tmp[i];
			dis = distance2(&re.pos, &ray->pos);
		}
	}
	re.texture = cylind->texture;
	re.rgb = cylind->rgb;
	return (re);
}
