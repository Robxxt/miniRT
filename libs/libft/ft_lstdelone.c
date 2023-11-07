/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:44:10 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 06:54:19 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Frees the memory of the node's content using del
and frees the node. The memory of next must not be freed.
@param lst: node
@param del: address of the function used to delete the content
*/
void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free_split(lst->content);
	free(lst);
}
