/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:26:49 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/15 03:13:34 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_surface	min_traces(t_surface *tmp, t_ray *ray)
{
	t_surface	re;
	int			i;
	float		tmp_dis;
	float		min_dis;

	min_dis = 3.4028235E38f;
	i = -1;
	re.pos.x = NAN;
	while (++i < 4)
	{
		if (!isnan(tmp[i].pos.x))
		{
			tmp_dis = distance2(&tmp[i].pos, &ray->pos);
			if (tmp_dis < min_dis)
			{
				re = tmp[i];
				min_dis = tmp_dis;
			}
		}
	}
	return (re);
}

t_surface	trace_obj(t_space *space, t_ray *ray)
{
	t_surface	re;
	t_surface	tmp[4];

	tmp[0] = trace_pl(&space->pl, ray);
	// printf("tmp0:[%f,%f,%f]\n", tmp[0].nv.x, tmp[0].nv.y, tmp[0].nv.z); 
	tmp[1] = trace_sp(&space->sp, ray);
	tmp[2] = trace_cyl(&space->cylind, ray);
	// printf("cubbef\n");
	tmp[3] = trace_cub(&space->cub, ray);
	// printf("cubaft\n");
	re = min_traces(tmp, ray);
	// printf("re:[%f,%f,%f]\n", re.nv.x, re.nv.y, re.nv.z); 
	return (re);
}

bool	is_shadow(t_space *space, t_ray *end, int i)
{
	t_surface	isend;
	t_vector	tmp;

	tmp = v_product(&end->nv, 0.001);
	end->pos = v_plus(&end->pos, &tmp);
	isend = trace_obj(space, end);
	if (isnan(isend.pos.x))
		return (false);
	if (distance2(&isend.pos, &end->pos)
		< distance2(&end->pos, &space->lit[i].pos))
		return (true);
	return (false);
}

t_color	get_tracing_color(t_space *space, t_ray *ray, t_surface *tmp, int i)
{
	t_color		re;
	// t_surface	point;
	t_ray		end;
	float		factor1;
	float		factor2;

	re = tmp->rgb;
	end.pos = tmp->pos;
	re.bright = 0;
	end.nv = v_minus(&space->lit[i].pos, &tmp->pos);
	end.nv = normized(end.nv);
	if (is_shadow(space, &end, i))
		return (re);
	re = color_reflect(&tmp->rgb, &space->lit[i].rgb);
	factor1 = dot_product(&end.nv, &tmp->nv);
	factor2 = -dot_product(&ray->nv, &tmp->nv);
	if (factor1 < 0.0f || factor2 < 0.0f)
		factor1 = 0.0f;
	factor1 = factor1 * factor2;
	re.bright = (unsigned int)((float)re.bright * powf(factor1, 2.0f));
	factor1 = powf(factor1, 32.0f);
	re.bright += (unsigned int)(factor1 * 50000.0f);
	return (re);
}

t_ray	next_ray(t_ray *ray, t_surface *tmp)
{
	t_ray		re;
	t_vector	tp;

	re.pos = tmp->pos;
	tp = v_product(&tmp->nv, -dot_product(&tmp->nv, &ray->nv));
	re.nv = v_plus(&tp, &ray->nv);
	re.nv = v_plus(&tp, &re.nv);
	tp = v_product(&re.nv, 0.001);
	re.pos = v_plus(&re.pos, &tp);
	return (re);
}

t_color	trace_rays(t_space *space, t_ray ray, int i)
{
	t_surface	tmp;
	t_color		re;
	t_color		abt;
	int			j;

	ft_bzero(&re, sizeof(re));
	j = 0;
	while (++j < 10)
	{
		tmp = trace_obj(space, &ray);
		if (isnan(tmp.pos.x) || tmp.texture != 'p')
			break;
		ray = next_ray(&ray, &tmp);
	}
	if (isnan(tmp.pos.x))
		return (re);
	while (i < 16 && !isnan(space->lit[i].pos.x))
	{
		abt = get_tracing_color(space, &ray, &tmp, i);
		re = color_mix(&abt, &re);
		// if (abt.bright != 8964U)
		// {
		// 	re = color_mix(&abt, &re);
		// 	j++;
		// }
		i++;
	}
	abt = color_reflect(&tmp.rgb, &space->ambient.rgb);
	re = color_mix(&abt, &re);
	// unsigned int x = 63;
	// re.bright += x;
	// re = color_mix(&abt, &re);
	return (color_normized(&re, ++i));
	// return (re);
}
