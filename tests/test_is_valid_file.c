/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:14:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/05 08:23:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_is_valid_file(void)
{
	printf("test_is_valid_file:\n");
	if (is_valid_file("images/.rt") == 1)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file(\"images/.rt\") == 1 💥\n");
	}
	if (is_valid_file("images/file1.rt") == 1)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file(\"images/file1.rt\") == 1 💥\n");
	}
	if (is_valid_file("images/hello.rt") == 0)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file(\"images/hello.rt\") == 1 💥\n");
	}
	if (is_valid_file("") == 0)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file(\"\") == 1 💥\n");
	}
	if (is_valid_file(NULL) == 0)
		printf("✅\n");
	else
	{
		printf("ERROR: test_is_valid_file(NULL) == 1 💥\n");
	}
}