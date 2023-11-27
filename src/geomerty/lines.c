/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:58:11 by tiqin             #+#    #+#             */
/*   Updated: 2023/11/27 21:11:43 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	distance2(t_vector a, t_vector b)
{
	float	re;

	re = 0;
	re += (a.x - b.x) * (a.x - b.x);
	re += (a.y - b.y) * (a.y - b.y);
	re += (a.z - b.z) * (a.z - b.z);
	return (re);
}

float	distance(t_vector a, t_vector b)
{
	float	re;

	re = 0;
	re += (a.x - b.x) * (a.x - b.x);
	re += (a.y - b.y) * (a.y - b.y);
	re += (a.z - b.z) * (a.z - b.z);
	return (sqrtf(re));
}
