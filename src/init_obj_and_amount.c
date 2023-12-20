/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_and_amount.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:04:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 12:04:49 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	init_amount(t_amount *a)
{
	a->lit = 0;
	a->pl = 0;
	a->sp = 0;
	a->cy = 0;
	a->cb = 0;
}

void	init_objects_exist_to_false(t_image *img)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		img->plane[i].exists = false;
		img->sphere[i].exists = false;
		img->cylinder[i].exists = false;
		img->cube[i].exists = false;
		i++;
	}
}
