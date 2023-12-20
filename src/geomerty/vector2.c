/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:14:00 by tiqin             #+#    #+#             */
/*   Updated: 2023/12/20 12:28:07 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vector	v_minus(t_vector *a, t_vector *b)
{
	t_vector	re;

	re.x = a->x - b->x;
	re.y = a->y - b->y;
	re.z = a->z - b->z;
	return (re);
}

float	dot_product(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vector	cross_product(t_vector *a, t_vector *b)
{
	t_vector	re;

	re.x = a->y * b->z - a->z * b->y;
	re.y = a->z * b->x - a->x * b->z;
	re.z = a->x * b->y - a->y * b->x;
	return (re);
}
