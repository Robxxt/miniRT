/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:06:47 by tiqin             #+#    #+#             */
/*   Updated: 2023/11/27 13:33:01 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_line	get_ray(t_camara *cmr, t_pixel *pix)
{
	t_line	re;
	float	anglx;
	float	angly;

	re.pos[0] = cmr->pos[0];
	re.pos[1] = cmr->pos[1];
	re.pos[2] = cmr->pos[2];
	anglx = (float)cmr->fv / (float)(pix->x - SCREEN_X / 2);
	angly = RASP_RATIO * (float)cmr->fv / (float)(pix->x - SCREEN_X / 2);

	return (re);
}
