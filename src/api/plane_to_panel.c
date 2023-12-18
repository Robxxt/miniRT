/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_to_panel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:09:17 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:40:57 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_sphere and t_sp
and fills p2 with the values from p1.
*/
void	plane_to_panel(t_plane p1, t_panel *p2)
{
	p2->exists = p1.exists;
	float_to_vector(p1.pos, &(p2->pos));
	float_to_vector(p1.nv, &(p2->nv));
	rgb_to_color(p1.rgb, &(p2->rgb));
	p2->texture = p1.texture;
}
