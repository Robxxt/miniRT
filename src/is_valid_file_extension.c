/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:07:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:25:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Returns true if the filename ends with .rt
*/
bool	is_valid_file_extension(char *filename)
{
	size_t	file_size;

	if (!filename)
		return (false);
	file_size = ft_strlen(filename);
	if (ft_strncmp(".rt", filename + file_size - 3, 4) == 0)
		return (true);
	return (false);
}
