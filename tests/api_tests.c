/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:08:17 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 15:23:52 by rdragan          ###   ########.fr       */
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
	print_color(color);
}

void	api_tests()
{
	test_rgb_to_color();
}