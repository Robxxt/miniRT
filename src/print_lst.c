/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:37:34 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 06:49:48 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;
	char	**sp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		sp = tmp->content;
		printf("{\n");
		for (int i = 0; sp[i]; i++)
		{
			printf("%s\n", sp[i]);
		}
		printf("}\n");
		
		tmp = tmp->next;
	}
}