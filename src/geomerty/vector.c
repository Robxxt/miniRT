/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:50 by tiqin             #+#    #+#             */
/*   Updated: 2023/11/27 20:53:44 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	model(t_vector a)
{
	return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vector	normized(t_vector a)
{
	float	mod;

	mod = model(a);
	a.x = a.x / mod;
	a.y = a.y / mod;
	a.z = a.z / mod;
	return (a);
}
