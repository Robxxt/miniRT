/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:01:29 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:16:20 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

# include "miniRT.h"

void	rgb_to_color(int rgb[3], t_color* color);
void	ambient_to_ambt(t_ambient a1, t_ambt* a2);
void	float_to_vector(float list[3], t_vector *v);
void	camara_to_cmr(t_camara a1, t_cmr* a2);
void	light_to_lit(t_light l1, t_lit* l2);
void	sphere_to_sp(t_sphere l1, t_sp* s2);
void	plane_to_panel(t_plane p1, t_panel* p2);
void	cylinder_to_cylind(t_cylinder p1, t_cylind* p2);
void	image_to_space(t_image p1, t_space* p2);

#endif