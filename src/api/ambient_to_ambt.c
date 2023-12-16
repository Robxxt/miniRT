/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_to_ambt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:27:24 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 15:31:01 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/api.h"

/*
Handles the differences between t_ambient and t_ambt
and fills a2 with the values from a1.
*/
void	ambient_to_ambt(t_ambient a1, t_ambt* a2)
{
	rgb_to_color(a1.rgb, &(a2->rgb));
	a2->rgb.bright = a1.r * 255; 
}