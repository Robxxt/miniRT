/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:06:11 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/05 08:22:25 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	is_valid_file(char *filename)
{
	int	fd;

	if (is_valid_file_extension(filename) == 0)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}
