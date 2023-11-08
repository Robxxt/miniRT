/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_cy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:55:33 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 10:07:18 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_cy(void)
{
	int	counter = 0;
	int	total_tests = 5;
	printf("test_validate_cy:\n");

	char *case0[] = {"Cy", "50.0,0.0,20.6", "0.0,0.0,1.0", "14.2", "21.42", "10,0,225", NULL};
	if (validate_cy(case0) == false)
		counter++;
	else
		printf("ERROR: test_validate_cy({\"Cy\", \"50.0,0.0,20.6\", \"0.0,0.0,1.0\", \"14.2\", \"21.42\", \"10,0,225\", NULL}) == false 💥\n");
	char *case1[] = {"cy", "50.0,0.0,20.6", "0.0,0.0,1.0", "14.2", "21.42", "10,0,225", NULL};
	if (validate_cy(case1) == true)
		counter++;
	else
		printf("ERROR: test_validate_cy({\"cy\", \"50.0,0.0,20.6\", \"0.0,0.0,1.0\", \"14.2\", \"21.42\", \"10,0,225\", NULL}) == true 💥\n");
	char *case2[] = {"cy", "50.0,0.0,20.6", "0.0,0.0,1.0", "a", "21.42", "10,0,225", NULL};
	if (validate_cy(case2) == false)
		counter++;
	else
		printf("ERROR: test_validate_cy({\"cy\", \"50.0,0.0,20.6\", \"0.0,0.0,1.0\", \"a\", \"21.42\", \"10,0,225\", NULL}) == false 💥\n");
	char *case3[] = {"cy", "50.0,0.0,20.6", "0.0,0.0,1.0", "14.2", "a", "10,0,225", NULL};
	if (validate_cy(case3) == false)
		counter++;
	else
		printf("ERROR: test_validate_cy({\"cy\", \"50.0,0.0,20.6\", \"0.0,0.0,1.0\", \"14.2\", \"a\", \"10,0,225\", NULL}) == false 💥\n");
	char *case4[] = {"cy", "50.0,0.0,20.6", "0.0,0.0,1.0", "14.2", "21.42", "10,a,225", NULL};
	if (validate_cy(case4) == false)
		counter++;
	else
		printf("ERROR: test_validate_cy({\"cy\", \"50.0,0.0,20.6\", \"0.0,0.0,1.0\", \"14.2\", \"21.42\", \"10,a,225\", NULL}) == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}