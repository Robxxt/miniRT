/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:19:20 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 11:25:28 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Returns true if s can be converted to rgb
*/
bool	validate_rgb(char *s)
{
	char	**tmp_list;
	int		tmp;
	int		i;

	if (!s)
		return (false);
	tmp_list = ft_split(s, ',');
	if (split_len(tmp_list) != 3)
	{
		free_split(tmp_list);
		return (false);
	}
	i = 0;
	while (tmp_list[i])
	{
		tmp = ft_atoi(tmp_list[i]);
		if (tmp < 0 || tmp > 255 || ft_str_isdigit(tmp_list[i]) == 0)
		{
			free_split(tmp_list);
			return (false);
		}
		i++;
	}
	free_split(tmp_list);
	return (true);
}