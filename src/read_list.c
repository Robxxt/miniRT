/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:16 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 16:23:39 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Set the values from the string inside the int list.
The int list must have only 3 items.
*/
void	read_int_list(int *list, char *s)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, ',');
	if (split_len(tmp) == 3)
	{
		i = 0;
		while (tmp[i])
		{
			list[i] = ft_atoi(tmp[i]);
			i++;
		}
	}
	free_split(tmp);
}
