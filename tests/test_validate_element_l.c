/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_element_l.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:48:29 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 07:19:29 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_element_l(void)
{
	int	counter = 0;
	int	total_tests = 7;
	printf("test_validate_element_l:\n");

	char *case1[] = {"L", "2,5", NULL};
	if (validate_element_l(case1) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_l(\"A\", \"2,5\") == false 💥\n");
	char *case2[] = {"L", "0.5,0.0,10.3", "0.5", "10, 255, 255", NULL};
	if (validate_element_l(case2) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_l({\"L\", \"0.5,0.0,10.3\", \"0.5\", \"10, 255, 255\"}) == true 💥\n");
	char *case3[] = {"L", "0.5,0.0,10.3", "0.5", "10, a, 255", NULL};
	if (validate_element_l(case3) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_l({\"L\", \"0.5,0.0,10.3\", \"0.5\", \"10, a, 255\"}) == false 💥\n");
	char *case4[] = {"L", "0.5,0.0,10.3", "0.5", NULL};
	if (validate_element_l(case4) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_l({\"L\", \"0.5,0.0,10.3\", \"0.5\"}) == true 💥\n");
	char *case5[] = {"L", "0.5,0.0,10.3", "-0.5", NULL};
	if (validate_element_l(case5) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_l({\"L\", \"0.5,0.0,10.3\", \"-0.5\"}) == false 💥\n");
	char *case6[] = {"L", "0.5,0.0,10.3", "1.5", NULL};
	if (validate_element_l(case6) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_l({\"L\", \"0.5,0.0,10.3\", \"1.5\"}) == false 💥\n");
	char *case7[] = {"L", "0.5,0.0,10.3", "1.5", "0,0,0", "123", NULL};
	if (validate_element_l(case7) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_l({\"L\", \"0.5,0.0,10.3\", \"1.5\", , \"0,0,0\", , \"123\"}) == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}