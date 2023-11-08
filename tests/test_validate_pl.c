/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_pl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:40:50 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 09:53:27 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_pl(void)
{
	int	counter = 0;
	int	total_tests = 8;
	printf("test_validate_pl:\n");

	char *case0[] = {"Pl", "0.0,0.0,-10.0", "0.0,1.0,0.0", "0,0,225", NULL};
	if (validate_pl(case0) == false)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"Pl\", \"0.0,0.0,-10.0\", \"0.0,1.0,0.0\", \"0,0,225\", NULL}) == false 💥\n");
	char *case1[] = {"pl", "0.0,0.0,-10.0", "0.0,1.0,0.0", "0,0,225", NULL};
	if (validate_pl(case1) == true)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"pl\", \"0.0,0.0,-10.0\", \"0.0,1.0,0.0\", \"0,0,225\", NULL}) == true 💥\n");
	char *case2[] = {"pl", "0.1,1.0,0.0", "0.0,1.0,0.0", "0,0,225", NULL};
	if (validate_pl(case2) == true)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"pl\", \"0.1,1.0,0.0\", \"0.0,1.0,0.0\", \"0,0,225\", NULL}) == true 💥\n");
	char *case3[] = {"pl", "0.1,1.0,a", "0.0,1.0,0.0", "0,0,225", NULL};
	if (validate_pl(case3) == false)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"pl\", \"0.1,1.0,a\", \"0.0,1.0,0.0\", \"0,0,225\", NULL}) == false 💥\n");
	char *case4[] = {"pl", "0.1,1.0,0", "0.0,1.0,a", "0,0,225", NULL};
	if (validate_pl(case4) == false)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"pl\", \"0.1,1.0,0\", \"0.0,1.0,a\", \"0,0,225\", NULL}) == false 💥\n");
	char *case5[] = {"pl", "0.1,1.0,0", "0.0,1.0,0.0", "0,0,a", NULL};
	if (validate_pl(case5) == false)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"pl\", \"0.1,1.0,0\", \"0.0,1.0,0.0\", \"0,0,a\", NULL}) == false 💥\n");
	char *case6[] = {"pl", "0.1,1.0,0", "0.0,1.0,0.0", "0,-1,225", NULL};
	if (validate_pl(case6) == false)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"pl\", \"0.1,1.0,0\", \"0.0,1.0,0.0\", \"0,-1,225\", NULL}) == false 💥\n");
	char *case7[] = {"pl", "0.1,1.0,0", "0.0,1.0,0.0", "0,1,256", NULL};
	if (validate_pl(case7) == false)
		counter++;
	else
		printf("ERROR: test_validate_pl({\"pl\", \"0.1,1.0,0\", \"0.0,1.0,0.0\", \"0,1,256\", NULL}) == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}