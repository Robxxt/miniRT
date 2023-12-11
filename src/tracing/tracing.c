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

	tmp[0] = trace_pl(space->pl, ray);
	tmp[1] = trace_sp(space->sp, ray);
	tmp[2] = trace_cyl(space->cylind, ray);
	tmp[3] = trace_cub(space->cylind, ray);
	re = min_traces(tmp, ray);
	return (re);
}

bool	is_end(t_space *space, t_ray *end, int i)
{
	t_surface	isend;

	isend = trace_obj(space, end);
	if (isnan(isend.pos.x))
		return (true);
	if (distance2(&isend.pos, &end->pos)
		< distance2(&end->pos, &space->lit[i].pos))
		return (false);
	return (true);
}

t_color	get_color(t_space *space, t_ray *ray, int i)
{
	t_color		re;
	t_surface	point;
	t_ray		end;

	re.bright = 0;
	re.r = 0;
	re.g = 0;
	re.b = 0;
	point = trace_obj(space, ray);
	if (isnan(point.pos.x))
		return (re);
	end.nv = v_minus(&space->lit[i].pos, &point.pos);
	end.nv = normized(end.nv);
	end.pos = point.pos;
	if (is_end(space, &end, i))
		return (re);
	re = color_reflect(&point.rgb, &space->lit[i]);
	re.bright = re.bright * 0.5f * (1.0f - dot_product(&end, ray));
	return (re);
}

t_color	trace_rays(t_space *space, t_ray ray, int i)
{
	t_surface	tmp;
	t_color		re;

	re.bright = 0;
	re.r = 0;
	re.g = 0;
	re.b = 0;
	while (ray.end == false)
	{
		tmp = trace_obj(space, &ray);
	}
	if (isnan(tmp.pos.x))
		return (re);
	return get_color(space, &ray, i);
}
