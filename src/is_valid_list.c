/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:17:32 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 07:47:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

/*
Checks if all the items of a list that has size of 3
are meeting a specific criteria set by function.
*/
bool    is_valid_int_list(char **list, bool (*function)(char *, int))
{
	int	tmp;
    int i;
    
    i = 0;
    while (i < 3)
    {
        if (ft_str_isdigit(list[i]) == 0)
            return (false);
		tmp = ft_atoi(list[i]);
        if (function(list[i], tmp) == false)
            return (false);
        i++;
    }
    return (true);
}

/*
Checks if all the items of a list that has size of 3
are meeting a specific criteria set by function.
*/
bool    is_valid_float_list(char **list, bool (*function)(char *, float))
{
	float	tmp;
    int i;
    
    i = 0;
    while (i < 3)
    {
        if (is_valid_float_number(list[i]) == false)
            return (false);
		tmp = ft_atof(list[i]);
        if (function(list[i], tmp) == false)
            return (false);
        i++;
    }
    return (true);
}