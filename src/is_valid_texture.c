/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:27:23 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 10:37:35 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	is_valid_texture(char *s, int type)
{
	if (ft_strlen(s) != 1)
		return (false);
	if (type == 0 && s[0] != 'n' && s[0] != 'c' && s[0] != 'p' && s[0] != 'b')
		return (false);
	if (type == 1 && s[0] != 'n' && s[0] != 'p')
		return (false);
	return (true);
}
