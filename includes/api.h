/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:01:29 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 15:24:07 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

# include "miniRT.h"

void	rgb_to_color(int rgb[3], t_color* color);

/*
tests
*/
void	api_tests();

#endif