/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:00:16 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 15:24:12 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	rgb_to_color(int rgb[3], t_color* color)
{
	color->r = rgb[0];
	color->g = rgb[1];
	color->b = rgb[2];
	color->bright = 255;
}
