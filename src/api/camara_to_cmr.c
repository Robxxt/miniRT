/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_to_cmr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:56:10 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 16:07:35 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_camera and t_cmr
and fills c2 with the values from c1.
*/
void	camara_to_cmr(t_camara c1, t_cmr* c2)
{
	float_to_vector(c1.pos, &(c2->pos));
	float_to_vector(c1.nv, &(c2->nv));
	c2->fv = c1.fv;
}
