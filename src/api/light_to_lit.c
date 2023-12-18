/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_to_lit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:41:13 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:40:43 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_light and t_lit
and fills l2 with the values from l1.
*/
void	light_to_lit(t_light l1, t_lit *l2)
{
	float_to_vector(l1.pos, &(l2->pos));
	rgb_to_color(l1.rgb, &(l2->rgb));
	l2->rgb.bright = l1.lb * 255;
}
