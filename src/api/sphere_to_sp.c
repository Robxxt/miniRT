/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_to_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:56:56 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:40:21 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_sphere and t_sp
and fills s2 with the values from s1.
*/
void	sphere_to_sp(t_sphere s1, t_sp *s2)
{
	s2->exists = s1.exists;
	float_to_vector(s1.pos, &(s2->pos));
	rgb_to_color(s1.rgb, &(s2->rgb));
	s2->radii = s1.d / 2;
	s2->texture = s1.texture;
}
