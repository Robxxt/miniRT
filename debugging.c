/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:32:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/17 12:11:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"
#include "includes/api.h"

void	print_color(t_color color)
{
	printf("r:%d\tg:%d\tb:%d\tbrightness:%d\n", color.r, color.g, color.b, color.bright);
}

void	print_vector(t_vector vector, char *s)
{
	printf("vector [%s]\t", s);
	printf("x: %f\ty: %f\tz: %f\n", vector.x, vector.y, vector.z);
}

void	print_panel(t_panel panel)
{
	printf("\tPANEL\n");
	printf("pos: %f,%f,%f\n", panel.pos.x, panel.pos.y, panel.pos.z);
	printf("nv: %f,%f,%f\n", panel.nv.x, panel.nv.y, panel.nv.z);
	printf("rgb: %d,%d,%d\n", panel.rgb.r, panel.rgb.g, panel.rgb.b);
	printf("texture: %c\n", panel.texture);
}

void	print_ambient(t_ambt a)
{
	printf("\tAMBIENT\n");
	print_color(a.rgb);
}

void	print_camara(t_cmr c)
{
	printf("\tCAMARA\n");
	print_vector(c.nv, "nv");
	print_vector(c.pos, "pos");
	printf("fv: %d\n", c.fv);
}

void	print_light(t_lit c)
{
	printf("\tLIGHT\n");
	print_vector(c.pos, "pos");
	print_color(c.rgb);
}

void	print_sp(t_sp sp)
{
	printf("\tSPHERE\n");
	printf("pos: %f,%f,%f\n", sp.pos.x, sp.pos.y, sp.pos.z);
	printf("rgb: %d,%d,%d\n", sp.rgb.r, sp.rgb.g, sp.rgb.b);
	printf("texture: %c\tradii: %f\n", sp.texture, sp.radii);
}

void	print_cy(t_cylind c)
{
	printf("\tCYLIND\n");
	print_vector(c.pos, "pos");
	print_vector(c.nv, "nv");
	print_color(c.rgb);
	printf("texture: %c\tradii: %f\theight: %f\n", c.texture, c.radii, c.height);
}

void	print_space(t_space s)
{
	printf("----------------------------\n");
	printf("	SPACE\n");
	printf("----------------------------\n");
	print_ambient(s.ambient);
	print_camara(s.cmr);
	print_light(s.lit[0]);
	if(s.sp[0].exists)
		print_sp(s.sp[0]);
	if(s.pl[0].exists)
		print_panel(s.pl[0]);
	if(s.cylind[0].exists)
		print_cy(s.cylind[0]);
}