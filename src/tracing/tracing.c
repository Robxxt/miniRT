/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:26:49 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/20 14:45:33 by tiqin            ###   ########.fr       */
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
	while (++i < 36)
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
	t_surface	tmp[36];
	int			i;

	i = 0;
	while (i < 9)
	{
		tmp[i * 4 + 0] = trace_pl(&space->pl[i], ray);
		tmp[i * 4 + 1] = trace_sp(&space->sp[i], ray);
		tmp[i * 4 + 2] = trace_cyl(&space->cylind[i], ray);
		tmp[i * 4 + 3] = trace_cub(&space->cub[i], ray);
		i++;
	}
	re = min_traces(tmp, ray);
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
	re.bright = (unsigned int)((float)re.bright * powf(factor1, 1.0f));
	if (!BONUS)
		return (re);
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
