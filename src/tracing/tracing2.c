/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:28:39 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/20 12:29:32 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

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
			break ;
		ray = next_ray(&ray, &tmp);
	}
	if (isnan(tmp.pos.x))
		return (re);
	while (i < 16 && !isnan(space->lit[i].pos.x))
	{
		abt = get_tracing_color(space, &ray, &tmp, i);
		re = color_mix(&abt, &re);
		i++;
	}
	abt = color_reflect(&tmp.rgb, &space->ambient.rgb);
	re = color_mix(&abt, &re);
	return (color_normized(&re, ++i));
}
