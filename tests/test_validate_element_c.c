/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_element_c.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:10:27 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 07:54:52 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_element_c(void)
{
	int	counter = 0;
	int	total_tests = 8;
	printf("test_validate_element_c:\n");

	char *case1[] = {"C", "2,5", NULL};
	if (validate_element_c(case1) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c(\"A\", \"2,5\") == false 💥\n");
	char *case2[] = {"C", "-50.0,0,20", "0,0,1", "70", NULL};
	if (validate_element_c(case2) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"-50.0,0,20\", \"0,0,1\", \"70\"}) == true 💥\n");
	char *case3[] = {"C", "-50.0,0,20", "0.2,0,0.3", "70", NULL};
	if (validate_element_c(case3) == true)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"-50.0,0,20\", \"0.2,0,0.3\", \"70\"}) == true 💥\n");
	char *case4[] = {"C", "-50.0,0,20", "1.3,0,0.3", "70", NULL};
	if (validate_element_c(case4) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"-50.0,0,20\", \"1.3,0,0.3\", \"70\"}) == false 💥\n");
	char *case5[] = {"C", "-50.0,0,20", "0,a,1", "70", NULL};
	if (validate_element_c(case5) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"-50.0,0,20\", \"0,a,1\", \"70\"}) == false 💥\n");
	char *case6[] = {"C", "-50.0,0,20", "0,0,0", "a", NULL};
	if (validate_element_c(case6) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"-50.0,0,20\", \"0,0,0\", \"a\"}) == false 💥\n");
	char *case7[] = {"C", "-50.0,0,20", "0,0,1", "-1", NULL};
	if (validate_element_c(case7) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"-50.0,0,20\", \"0,0,1\", \"-1\"}) == false 💥\n");
	char *case8[] = {"C", "-50.0,0,20", "0,0,1", "182", NULL};
	if (validate_element_c(case8) == false)
		counter++;
	else
		printf("ERROR: test_validate_element_c({\"L\", \"-50.0,0,20\", \"0,0,1\", \"182\"}) == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}