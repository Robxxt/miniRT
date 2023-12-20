/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:06:47 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/20 12:13:05 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vector	get_v(t_vector *cmr, float beta)
{
	t_vector	re;
	float		lambda;

	if (cmr->z == 0)
	{
		re.x = 0.0f;
		re.y = 0.0f;
		re.z = tanf(beta);
		return (re);
	}
	lambda = tanf(beta);
	re.x = -cmr->z * cmr->x / sqrtf(cmr->x * cmr->x + cmr->y * cmr->y);
	re.y = -cmr->z * cmr->y / sqrtf(cmr->x * cmr->x + cmr->y * cmr->y);
	re.z = sqrtf(cmr->x * cmr->x + cmr->y * cmr->y);
	re = v_product(&re, lambda);
	return (re);
}

t_vector	get_h(t_vector *cmr, float aph)
{
	t_vector	re;
	float		lambda;

	lambda = tanf(aph);
	re.x = cmr->y;
	re.y = -cmr->x;
	re.z = 0.0f;
	re = normized(re);
	re = v_product(&re, lambda);
	return (re);
}

t_vector	camera_nv(t_cmr *cmr, float aph, float beta)
{
	t_vector	re;
	t_vector	h;
	t_vector	v;

	if (cmr->nv.z == 1.0f || cmr->nv.z == -1.0f)
	{
		re.x = tanf(aph) * cmr->nv.z;
		re.y = tanf(beta) * cmr->nv.z;
		re.z = cmr->nv.z;
		return (normized(re));
	}
	re.x = cmr->nv.x;
	re.y = cmr->nv.y;
	re.z = cmr->nv.z;
	h = get_h(&re, aph);
	v = get_v(&re, beta);
	re = v_plus(&re, &h);
	re = v_plus(&re, &v);
	re = normized(re);
	return (re);
}

t_ray	camera_ray(t_cmr *cmr, t_pixel *pix)
{
	t_ray	re;
	float	anglx;
	float	angly;
	float	res;

	re.pos = cmr->pos;
	re.end = false;
	res = (float)cmr->fv / (float)SCREEN_X * DEG_RAD;
	anglx = (float)(pix->x - SCREEN_X / 2) * res;
	angly = (float)(pix->y - SCREEN_Y / 2) * res;
	re.nv = camera_nv(cmr, anglx, -angly);
	return (re);
}
