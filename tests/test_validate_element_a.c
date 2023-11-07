/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_element_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:23:20 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 10:18:20 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_element_a(void)
{
	int	counter = 0;
	int	total_tests = 8;
	printf("test_validate_element_a:\n");

	char *case1[] = {"A", "2,5"};
	if (validate_element_a(case1) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"2,5\") == false 💥\n");
	char *case2[] = {"A", "0.5"};
	if (validate_element_a(case2) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"0.5\") == false 💥\n");
	char *case3[] = {"A", "2.5", "255"};
	if (validate_element_a(case3) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"2.5\", \"255\") == false 💥\n");
	char *case4[] = {"A", "2.5", "255,255"};
	if (validate_element_a(case4) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"2.5\", \"255,255\") == false 💥\n");
	char *case5[] = {"A", "0.5", "255,255,255"};
	if (validate_element_a(case5) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"0.5\", \"255,255,255\") == true 💥\n");
	char *case6[] = {"A", "2.5", "255,0,255"};
	if (validate_element_a(case6) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"2.5\", \"255,0,255\") == false 💥\n");
	char *case7[] = {"A", "2.5", "0,0,0"};
	if (validate_element_a(case7) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"2.5\", \"0,0,0\") == false 💥\n");
	char *case8[] = {"A", "0.5", "0,-1,0"};
	if (validate_element_a(case8) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_a(\"A\", \"0.5\", \"0,-1,0\") == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}