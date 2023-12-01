/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:06:47 by tiqin             #+#    #+#             */
/*   Updated: 2023/11/27 13:33:01 by tiqin            ###   ########.fr       */
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
	lambda = 1.0f - cmr->z * cmr->z;
	lambda = lambda + lambda * lambda / cmr->z / cmr->z;
	lambda = tanf(beta) / sqrtf(1.0f - cmr->z * cmr->z);
	re.x = cmr->y;
	re.y = -cmr->x;
	re.z = 0.0f;
	re = v_product(&re, lambda);
	return (re);
}

t_vector	get_h(t_vector *cmr, float aph)
{
	t_vector	re;
	float		lambda;

	lambda = tanf(aph) / sqrtf(1.0f - cmr->z * cmr->z);
	re.x = cmr->y;
	re.y = -cmr->x;
	re.z = 0.0f;
	re = v_product(&re, lambda);
	return (re);
}

t_vector	camera_nv(t_camara *cmr, float aph, float beta)
{
	t_vector	re;
	t_vector	h;
	t_vector	v;

	if (cmr->pos[2] == 1.0f)
	{
		re.x = 0.0f;
		re.y = 0.0f;
		re.z = 1.0f;
		return (re);
	}
	re.x = cmr->nv[0];
	re.y = cmr->nv[1];
	re.z = cmr->nv[2];
	h = get_h(&re, aph);
	v = get_v(&re, beta);
	re = v_plus(&re, &h);
	re = v_plus(&re, &v);
	re = normized(re);
	return (re);
}

t_ray	camera_ray(t_camara *cmr, t_pixel *pix)
{
	t_ray	re;
	float	anglx;
	float	angly;

	re.pos.x = cmr->pos[0];
	re.pos.y = cmr->pos[1];
	re.pos.z = cmr->pos[2];
	re.end = false;
	anglx = (float)cmr->fv / (float)(pix->x - SCREEN_X / 2);
	angly = RASP_RATIO * (float)cmr->fv / (float)(pix->y - SCREEN_X / 2);

	re.nv = camera_nv(cmr, anglx, angly);
	return (re);
}
