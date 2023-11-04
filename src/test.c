/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 07:57:27 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/04 09:23:32 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libs/libft/libft.h"

int	main(void)
{
	char	**out;

	out = ft_split("Hi tehre!", ' ');
	for (int i = 0; out[i]; i++)
		printf("%s\n", out[i]);
	free_split(out);
	return (0);
}
