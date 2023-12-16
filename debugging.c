/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:32:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"
#include "includes/api.h"

void	print_color(t_color color)
{
	printf("r:%d\tg:%d\tb:%d\tbrightness:%d\n", color.r, color.g, color.b, color.bright);
}

void	print_vector(t_vector vector)
{
	printf("x: %f\ty: %f\tz: %f\n", vector.x, vector.y, vector.z);
}

void	print_panel(t_panel panel)
{
	printf("PANEL\n");
	printf("pos: %f,%f,%f\n", panel.pos.x, panel.pos.y, panel.pos.z);
	printf("nv: %f,%f,%f\n", panel.nv.x, panel.nv.y, panel.nv.z);
	printf("rgb: %d,%d,%d\n", panel.rgb.r, panel.rgb.g, panel.rgb.b);
	printf("texture: %c\n", panel.texture);
}