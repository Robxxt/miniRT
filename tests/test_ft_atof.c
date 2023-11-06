/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 05:16:44 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/06 06:41:08 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_get_integer_part(void)
{
	int	counter = 0;
	int	total_tests = 4;
	printf("test_get_integer_part:\n");
	
	if (get_integer_part("123") == 123)
		counter++;
	else
		printf("ERROR: test_get_integer_part(\"123\") == 123 💥\n");
	
	if (get_integer_part("0") == 0.0)
		counter++;
	else
		printf("ERROR: test_get_integer_part(\"0\") == 0.0 💥\n");
	
	if (get_integer_part("-123") == -123)
		counter++;
	else
		printf("ERROR: test_get_integer_part(\"-123\") == -123 💥\n");
	if (get_integer_part("1421.44127") == 1421)
		counter++;
	else
		printf("ERROR: test_get_integer_part(\"1421.44127\") == 1421 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}

void	test_ft_atof(void)
{
	int	counter = 0;
	int	total_tests = 7;
	printf("test_ft_atof:\n");

	if (ft_atof("Hola") == 0.0)
		counter++;
	else
		printf("ERROR: test_ft_atof(\"Hola\") == 0.0 💥\n");
	
	if (ft_atof("123") == 123.0)
		counter++;
	else
		printf("ERROR: test_ft_atof(\"123\") == 123.0 💥\n");
	
	if (ft_atof("123.1234") == 123.1234)
		counter++;
	else
		printf("ERROR: test_ft_atof(\"123.1234\") == 123.1234 💥\n");
	
	if (ft_atof("-123.1234") == -123.1234)
		counter++;
	else
		printf("ERROR: test_ft_atof(\"-123.1234\") == -123.1234 💥\n");
	
	if (ft_atof("0") == 0.0)
		counter++;
	else
		printf("ERROR: test_ft_atof(\"0\") == 0.0 💥\n");
	
	if (ft_atof("-123") == -123.0)
		counter++;
	else
		printf("ERROR: test_ft_atof(\"-123\") == -123.0 💥\n");
	if (ft_atof("4124214212344127") == 0.0)
		counter++;
	else
		printf("ERROR: test_ft_atof(\"4124214212344127\") == 0.0 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}