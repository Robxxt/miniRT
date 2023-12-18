/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:37:34 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:47:22 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;
	char	**sp;
	int		i;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		sp = tmp->content;
		printf("{\n");
		i = -1;
		while (sp[++i])
			printf("%s\n", sp[i]);
		printf("}\n");
		tmp = tmp->next;
	}
}
