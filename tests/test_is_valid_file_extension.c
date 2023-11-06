/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_file_extension.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:09:09 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/06 05:07:31 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_is_valid_file_extension(void)
{
	int	counter = 0;
	int	total_tests = 5;
	printf("test_is_valid_file_extension:\n");
	if (is_valid_file_extension(".rt") == 1)
		counter++;
	else
	{
		printf("ERROR: test_is_valid_file_extension(\".rt\") == 1 💥\n");
	}
	if (is_valid_file_extension(".rta") == 0)
		counter++;
	else
	{
		printf("ERROR: test_is_valid_file_extension(\".rta\") == 1 💥\n");
	}
	if (is_valid_file_extension(".art") == 0)
		counter++;
	else
	{
		printf("ERROR: test_is_valid_file_extension(\".art\") == 1 💥\n");
	}
	if (is_valid_file_extension("") == 0)
		counter++;
	else
	{
		printf("ERROR: test_is_valid_file_extension(\"\") == 1 💥\n");
	}
	if (is_valid_file_extension(NULL) == 0)
		counter++;
	else
	{
		printf("ERROR: test_is_valid_file_extension(NULL) == 1 💥\n");
	}
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}