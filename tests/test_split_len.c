/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:26:40 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 10:41:39 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_split_len(void)
{
	int	counter = 0;
	int	total_tests = 5;
	printf("test_split_len:\n");

	char *case1[] = {"A", "2,5", NULL};
	if (split_len(case1) == 2)
		counter++;
	else
		printf("ERROR: test_split_len({\"A\", \"2,5\"}) == 2 💥\n");
	char *case2[] = {"A", "0.5", "412", NULL};
	if (split_len(case2) == 3)
		counter++;
	else
		printf("ERROR: test_split_len({\"A\", \"0.5\", \"412\"}) == 3 💥\n");
	char *case3[] = {"A", NULL};
	if (split_len(case3) == 1)
		counter++;
	else
		printf("ERROR: test_split_len({\"A\"}) == 1 💥\n");
	char *case4[] = {NULL};
	if (split_len(case4) == 0)
		counter++;
	else
		printf("ERROR: test_split_len({NULL}) == 0 💥\n");
	if (split_len(NULL) == 0)
		counter++;
	else
		printf("ERROR: test_split_len(NULL) == 0 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}