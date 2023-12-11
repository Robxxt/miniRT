/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:29:29 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/11 21:30:47 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	delta(float a, float b, float c)
{
	return (b * b - 4 * a * c);
}

float	root_minus(float a, float b, float c)
{
	float	re;

	re = -b - sqrtf(delta(a, b, c));
	re = re * 0.5f / a;
	return (re);
}

float	root_plus(float a, float b, float c)
{
	float	re;

	re = -b + sqrtf(delta(a, b, c));
	re = re * 0.5f / a;
	return (re);
}
