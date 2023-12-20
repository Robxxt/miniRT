/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:12:21 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 12:13:21 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

unsigned int	get_color(t_color *rgb)
{
	unsigned int	c;

	c = 0U;
	if (rgb->b > 255U)
		c = c + 255U;
	else
		c = c + rgb->b;
	if (rgb->g > 255U)
		c = c + 0x00000100U * 255U;
	else
		c = c + 0x00000100U * rgb->g;
	if (rgb->r > 255U)
		c = c + 0x00010000U * 255U;
	else
		c = c + 0x00010000U * rgb->r;
	if (rgb->bright < 255U)
		c = c + 0x01000000U * (255U - rgb->bright);
	return (c);
}

t_color	color_mix(t_color *a, t_color *b)
{
	t_color	re;

	re.bright = a->bright + b->bright;
	re.b = (a->b + b->b);
	re.g = (a->g + b->g);
	re.r = (a->r + b->r);
	return (re);
}

t_color	color_reflect(t_color *a, t_color *b)
{
	t_color	re;

	re.bright = a->bright * b->bright / 255;
	re.b = a->b * b->b / 255;
	re.g = a->g * b->g / 255;
	re.r = a->r * b->r / 255;
	return (re);
}

t_color	color_normized(t_color *a, unsigned int n)
{
	t_color	re;

	re.b = a->b / n;
	re.g = a->g / n;
	re.r = a->r / n;
	return (re);
}
