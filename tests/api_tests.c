/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:08:17 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 16:11:15 by rdragan          ###   ########.fr       */
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

void	api_tests()
{
	test_rgb_to_color();
	test_ambient_to_ambt();
	test_float_to_vector();
	test_camara_to_cmr();
}