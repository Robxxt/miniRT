/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_element_c.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:10:27 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 17:11:34 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_element_c(void)
{
	int	counter = 0;
	int	total_tests = 7;
	printf("test_validate_element_c:\n");

	char *case1[] = {"L", "2,5", NULL};
	if (validate_element_c(case1) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c(\"A\", \"2,5\") == false 💥\n");
	char *case2[] = {"L", "0.5,0.0,10.3", "0.5,0,0", "10", NULL};
	if (validate_element_c(case2) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"0.5,0.0,10.3\", \"0.5\", \"10\"}) == true 💥\n");
	char *case3[] = {"L", "0.5,0.0,10.3", "0.9", "10", NULL};
	if (validate_element_c(case3) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"0.5,0.0,10.3\", \"0.9\", \"10\"}) == true 💥\n");
	char *case4[] = {"L", "0.5,0.0,10.3", "1.1", "10", NULL};
	if (validate_element_c(case4) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"0.5,0.0,10.3\", \"1.1\", \"10\"}) == false 💥\n");
	char *case5[] = {"L", "0.5,0.0,10.3", "1.0", "180", NULL};
	if (validate_element_c(case5) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"0.5,0.0,10.3\", \"1.0\", \"180\"}) == true 💥\n");
	char *case6[] = {"L", "0.5,0.0,10.3", "1.1", "-10", NULL};
	if (validate_element_c(case6) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"0.5,0.0,10.3\", \"1.1\", \"-10\"}) == false 💥\n");
	char *case7[] = {"L", "0.5,0.0,10.3", "1.0", "190", NULL};
	if (validate_element_c(case7) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"0.5,0.0,10.3\", \"1.0\", \"190\"}) == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}