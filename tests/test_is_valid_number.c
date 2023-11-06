/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 05:28:44 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/06 06:30:15 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_is_valid_number(void)
{
	int	counter = 0;
	int	total_tests = 17;
	printf("test_is_valid_number:\n");

	if (is_valid_number("Hola") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"Hola\") == false 💥\n");
	if (is_valid_number("123") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"123\") == true 💥\n");
	if (is_valid_number("0") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"0\") == true 💥\n");
	if (is_valid_number("123.42") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"123.42\") == true 💥\n");
	if (is_valid_number("-123.42") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"-123.42\") == true 💥\n");
	if (is_valid_number("+123.42") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"+123.42\") == true 💥\n");
	if (is_valid_number("-123") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"-123\") == true 💥\n");
	if (is_valid_number("--123") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"--123\") == false 💥\n");
	if (is_valid_number("-+123") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"-+123\") == false 💥\n");
	if (is_valid_number("++123") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"++123\") == false 💥\n");
	if (is_valid_number("+123a") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"+123a\") == false 💥\n");
	if (is_valid_number("+1a23") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"+1a23\") == false 💥\n");
	if (is_valid_number("+a123") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"+a123\") == false 💥\n");
	if (is_valid_number("2147483646") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"2147483646\") == true 💥\n");
	if (is_valid_number("-2147483647") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"-2147483647\") == true 💥\n");
	if (is_valid_number("2147483647") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"2147483647\") == false 💥\n");
	if (is_valid_number("-2147483648") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_number(\"-2147483648\") == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}