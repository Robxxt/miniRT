/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:08:17 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 18:22:19 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"
#include "../includes/api.h"

void	test_rgb_to_color()
{
	int	rgb[] = {0, 1, 2};
	t_color	color;
	
	printf("test_rgb_to_color(): ");
	rgb_to_color(rgb, &color);
	if (color.r == 0 && color.g == 1 && color.b == 2 && color.bright == 255)
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	test_ambient_to_ambt()
{
	t_ambient	a;
	t_ambt		a2;
	a.r = 0.4;
	a.rgb[0] = 0;
	a.rgb[1] = 1;
	a.rgb[2] = 2;

	ambient_to_ambt(a, &a2);
	printf("test_rgb_to_color(): ");
	if (a2.rgb.r == (unsigned int)a.rgb[0] && a2.rgb.g == (unsigned int)a.rgb[1] && a2.rgb.b == (unsigned int)a.rgb[2] &&
		a2.rgb.bright == (a.r * 255))
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	test_float_to_vector()
{
	float	l[] = {0.1, 0.2, 0.3};
	t_vector v;

	float_to_vector(l, &v);
	printf("test_float_to_vector(): ");
	if (v.x == l[0] && v.y == l[1] && v.z == l[2])
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	test_camara_to_cmr()
{
	t_camara c1;
	t_cmr	 c2;

	c1.pos[0] = 0.1;
	c1.pos[1] = 1.1;
	c1.pos[2] = 2.1;
	c1.nv[0] = 0.1;
	c1.nv[1] = 1.1;
	c1.nv[2] = 2.1;
	c1.fv = 1;
	printf("test_camara_to_cmr(): ");
	camara_to_cmr(c1, &(c2));
	if (c1.pos[0] == c2.pos.x && c1.pos[1] == c2.pos.y && c1.pos[2] == c2.pos.z &&
		c1.nv[0] == c2.nv.x && c1.nv[1] == c2.nv.y && c1.nv[2] == c2.nv.z &&
		c1.fv == c2.fv)
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	test_light_to_lit()
{
	t_light	l1;
	t_lit	l2;

	printf("test_light_to_lit(): ");
	l1.pos[0] = 0.1;
	l1.pos[1] = 1.1;
	l1.pos[2] = 2.1;
	l1.rgb[0] = 0;
	l1.rgb[1] = 1;
	l1.rgb[2] = 2;
	l1.lb = 0.4;
	light_to_lit(l1, &(l2));
	if (l1.pos[0] == l2.pos.x && l1.pos[1] == l2.pos.y && l1.pos[2] == l2.pos.z &&
		(unsigned int)l1.rgb[0] == l2.rgb.r && (unsigned int)l1.rgb[1] == l2.rgb.g && (unsigned int)l1.rgb[2] == l2.rgb.b &&
		(l1.lb * 255) == l2.rgb.bright)
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	test_sphere_to_sp()
{
	t_sphere	s1;
	t_sp	s2;

	printf("test_sphere_to_sp(): ");
	s1.exists = true;
	s1.pos[0] = 0.1;
	s1.pos[1] = 1.1;
	s1.pos[2] = 2.1;
	s1.rgb[0] = 0;
	s1.rgb[1] = 1;
	s1.rgb[2] = 2;
	sphere_to_sp(s1, &(s2));
	if (s1.pos[0] == s2.pos.x && s1.pos[1] == s2.pos.y && s1.pos[2] == s2.pos.z &&
		(unsigned int)s1.rgb[0] == s2.rgb.r && (unsigned int)s1.rgb[1] == s2.rgb.g && (unsigned int)s1.rgb[2] == s2.rgb.b &&
		s1.d == s2.radii && s1.exists == s2.exists)
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	test_plane_to_panel()
{
	t_plane p1;
	t_panel	p2;

	printf("test_plane_to_panel(): ");
	p1.exists = true;
	p1.pos[0] = 0.1;
	p1.pos[1] = 1.1;
	p1.pos[2] = 2.1;
	p1.rgb[0] = 0;
	p1.rgb[1] = 1;
	p1.rgb[2] = 2;
	p1.nv[0] = 0;
	p1.nv[1] = 1;
	p1.nv[2] = 2;
	plane_to_panel(p1, &p2);
	if (p1.pos[0] == p2.pos.x && p1.pos[1] == p2.pos.y && p1.pos[2] == p2.pos.z &&
		(unsigned int)p1.rgb[0] == p2.rgb.r && (unsigned int)p1.rgb[1] == p2.rgb.g && (unsigned int)p1.rgb[2] == p2.rgb.b &&
		 p1.exists == p2.exists)
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	test_cylinder_to_cylind()
{
	t_cylinder p1;
	t_cylind	p2;

	printf("test_cylinder_to_cylind(): ");
	p1.exists = true;
	p1.pos[0] = 0.1;
	p1.pos[1] = 1.1;
	p1.pos[2] = 2.1;
	p1.rgb[0] = 0;
	p1.rgb[1] = 1;
	p1.rgb[2] = 2;
	p1.nv[0] = 0;
	p1.nv[1] = 1;
	p1.nv[2] = 2;
	cylinder_to_cylind(p1, &p2);
	if (p1.pos[0] == p2.pos.x && p1.pos[1] == p2.pos.y && p1.pos[2] == p2.pos.z &&
		(unsigned int)p1.rgb[0] == p2.rgb.r && (unsigned int)p1.rgb[1] == p2.rgb.g && (unsigned int)p1.rgb[2] == p2.rgb.b &&
		 p1.exists == p2.exists && p2.radii == (p1.d / 2) && p1.h == p2.height)
		printf("✅");
	else
		printf("💥");
	printf("\n");
}

void	api_tests()
{
	test_rgb_to_color();
	test_ambient_to_ambt();
	test_float_to_vector();
	test_camara_to_cmr();
	test_light_to_lit();
	test_sphere_to_sp();
	test_plane_to_panel();
	test_cylinder_to_cylind();
}
