/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:55:56 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/20 12:16:33 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_surface	trace_side(t_line *pl, t_ray *ray)
{
	t_surface	re;
	float		lambda;

	re.pos.x = NAN;
	lambda = dot_product(&pl->pos, &pl->nv) - dot_product(&ray->pos, &pl->nv);
	lambda = lambda / dot_product(&ray->nv, &pl->nv);
	if (lambda < 0.0f)
		return (re);
	re.pos = v_product(&ray->nv, lambda);
	re.pos = v_plus(&ray->pos, &re.pos);
	re.nv = pl->nv;
	return (re);
}

bool	in_cube(t_surface *tmp, t_cub *cub, int i)
{
	t_vector	v;
	int			j;

	if (i > 3)
		i = 7 - i;
	j = i + 1;
	if (j == 4)
		j = 1;
	v = v_minus(&cub->side[j].pos, &tmp->pos);
	if (dot_product(&v, &cub->side[j].nv) < 0.0f)
		return (false);
	v = v_minus(&cub->side[7 - j].pos, &tmp->pos);
	if (dot_product(&v, &cub->side[7 - j].nv) < 0.0f)
		return (false);
	j = j + 1;
	if (j == 4)
		j = 1;
	v = v_minus(&cub->side[j].pos, &tmp->pos);
	if (dot_product(&v, &cub->side[j].nv) < 0.0f)
		return (false);
	v = v_minus(&cub->side[7 - j].pos, &tmp->pos);
	if (dot_product(&v, &cub->side[7 - j].nv) < 0.0f)
		return (false);
	return (true);
}

/*
** cube sides: up down, left right, front back
**		index: 1  6     2    5      3     4
*/

t_surface	trace_cub(t_cub *cub, t_ray *ray)
{
	t_surface	re;
	t_surface	tmp;
	int			i;
	float		dis;

	re.pos.x = NAN;
	if (cub->exists == false)
		return (re);
	dis = 3.4028235E38f;
	i = -1;
	while (++i < 7)
	{
		tmp = trace_side(&cub->side[i], ray);
		if (isnan(tmp.pos.x) || !in_cube(&tmp, cub, i))
			continue ;
		if (distance2(&tmp.pos, &ray->pos) < dis)
		{
			re = tmp;
			dis = distance2(&re.pos, &ray->pos);
		}
	}
	re.texture = cub->texture;
	re.rgb = cub->rgb;
	return (re);
}
