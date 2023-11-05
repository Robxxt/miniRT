/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_file_extension.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:09:09 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/05 08:21:47 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_is_valid_file_extension(void)
{
	printf("test_is_valid_file_extension:\n");
	if (is_valid_file_extension(".rt") == 1)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file_extension(\".rt\") == 1 💥\n");
	}
	if (is_valid_file_extension(".rta") == 0)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file_extension(\".rta\") == 1 💥\n");
	}
	if (is_valid_file_extension(".art") == 0)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file_extension(\".art\") == 1 💥\n");
	}
	if (is_valid_file_extension("") == 0)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file_extension(\"\") == 1 💥\n");
	}
	if (is_valid_file_extension(NULL) == 0)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file_extension(NULL) == 1 💥\n");
	}
}