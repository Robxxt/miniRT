/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:15:31 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 15:16:44 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	print_color(t_color color)
{
	printf("r:%d\tg:%d\tb:%d\tbrightness:%d\n", color.r, color.g, color.b, color.bright);
}