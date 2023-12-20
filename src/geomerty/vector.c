/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:50 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/20 12:14:18 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	module2(t_vector *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

float	module(t_vector *a)
{
	return (sqrtf(a->x * a->x + a->y * a->y + a->z * a->z));
}

t_vector	normized(t_vector a)
{
	float	mod;

	mod = module(&a);
	a.x = a.x / mod;
	a.y = a.y / mod;
	a.z = a.z / mod;
	return (a);
}

t_vector	v_product(t_vector *a, float b)
{
	t_vector	re;

	re.x = a->x * b;
	re.y = a->y * b;
	re.z = a->z * b;
	return (re);
}

t_vector	v_plus(t_vector *a, t_vector *b)
{
	t_vector	re;

	re.x = a->x + b->x;
	re.y = a->y + b->y;
	re.z = a->z + b->z;
	return (re);
}
