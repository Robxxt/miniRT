/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:58:11 by tiqin             #+#    #+#             */
/*   Updated: 2023/11/27 18:19:55 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	distance2(float a[3], float b[3])
{
	float	re;

	re = 0;
	re += (a[0] - b[0]) * (a[0] - b[0]);
	re += (a[1] - b[1]) * (a[1] - b[1]);
	re += (a[2] - b[2]) * (a[2] - b[2]);
	return (re);
}

float	distance(float a[3], float b[3])
{
	float	re;

	re = 0;
	re += (a[0] - b[0]) * (a[0] - b[0]);
	re += (a[1] - b[1]) * (a[1] - b[1]);
	re += (a[2] - b[2]) * (a[2] - b[2]);
	return (sqrtf(re));
}

void	get_pptl()