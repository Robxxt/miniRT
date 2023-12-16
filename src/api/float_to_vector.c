/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:59:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 16:01:57 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Takes a float array data and fills a vector.
*/
void	float_to_vector(float list[3], t_vector *v)
{
	v->x = list[0];
	v->y = list[1];
	v->z = list[2];
}
