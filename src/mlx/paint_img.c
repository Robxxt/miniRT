/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:48:24 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/13 08:54:45 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	paint_pixel(t_vars *vars, t_pixel pos, int color)
{
	char	*dst;

	dst = vars->addr + (pos.y * vars->l_len + pos.x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
}
