/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_sp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:26:46 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 08:43:53 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_sp(void)
{
	int	counter = 0;
	int	total_tests = 10;
	printf("test_validate_sp:\n");

	char *case0[] = {"Sp", "0.0,0.0,20.6", "12.6", "10,0,255", NULL};
	if (validate_sp(case0) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"Sp\", \"0.0,0.0,20.6\", \"12.6\", \"10,0,255\", NULL}) == false 💥\n");
	char *case1[] = {"sp", "2,5", NULL};
	if (validate_sp(case1) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp(\"A\", \"2,5\") == false 💥\n");
	char *case2[] = {"sp", "0.0,0.0,20.6", "12.6", "10,0,255", NULL};
	if (validate_sp(case2) == true)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,0.0,20.6\", \"12.6\", \"10,0,255\", NULL}) == true 💥\n");
	char *case3[] = {"sp", "0.0,0.0,20.6", "15", "10,0,255", NULL};
	if (validate_sp(case3) == true)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,0.0,20.6\", \"15\", \"10,0,255\", NULL}) == true 💥\n");
	char *case4[] = {"sp", "0.0,a,20.6", "12.6", "10,0,255", NULL};
	if (validate_sp(case4) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,a,20.6\", \"12.6\", \"10,0,255\", NULL}) == false 💥\n");
	char *case5[] = {"sp", "0.0,0.0,20.6", "a", "10,0,255", NULL};
	if (validate_sp(case5) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,0.0,20.6\", \"a\", \"10,0,255\", NULL}) == false 💥\n");
	char *case6[] = {"sp", "0.0,0.0,20.6", "12.6", "10,0,a", NULL};
	if (validate_sp(case6) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,0.0,20.6\", \"12.6\", \"10,0,a\", NULL}) == false 💥\n");
	char *case7[] = {"sp", "0.0,0.0,20.6", "12.6", "10,0,-14", NULL};
	if (validate_sp(case7) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,0.0,20.6\", \"12.6\", \"10,0,-14\", NULL}) == false 💥\n");
	char *case8[] = {"sp", "0.0,0.0,20.6", "12.6", "10,0,256", NULL};
	if (validate_sp(case8) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,0.0,20.6\", \"12.6\", \"10,0,256\", NULL}) == false 💥\n");
	char *case9[] = {"sp", "0.0,0.0,20.6", "12.6", "10,0,-14", "145", NULL};
	if (validate_sp(case9) == false)
		counter++;
	else
		printf("ERROR: test_validate_sp({\"sp\", \"0.0,0.0,20.6\", \"12.6\", \"10,0,-14\", \"145\", NULL}) == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}