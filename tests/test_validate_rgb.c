/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:20:54 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 10:24:29 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_validate_rgb(void)
{
	int	counter = 0;
	int	total_tests = 8;
	printf("test_validate_rgb:\n");

	if (validate_rgb("255,255,255") == true)
		counter++;
	else
		printf("ERROR: test_validate_rgb(\"255,255,255\") == true 💥\n");
	if (validate_rgb("255,-1,255") == false)
		counter++;
	else
		printf("ERROR: test_validate_rgb(\"255,-1,255\") == false 💥\n");
	if (validate_rgb("") == false)
		counter++;
	else
		printf("ERROR: test_validate_rgb(\"\") == false 💥\n");
	if (validate_rgb(NULL) == false)
		counter++;
	else
		printf("ERROR: test_validate_rgb(NULL) == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}