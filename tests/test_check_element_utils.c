/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_element_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:58:12 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/07 09:04:46 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_is_valid_element_type(void)
{
	int	counter = 0;
	int	total_tests = 11;
	printf("test_is_valid_element_type:\n");
	
	if (is_valid_element_type("123") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"123\") == false 💥\n");
	
	if (is_valid_element_type("AC") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"AC\") == false 💥\n");
	
	if (is_valid_element_type("A") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"A\") == true 💥\n");
	if (is_valid_element_type("C") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"C\") == true 💥\n");
	if (is_valid_element_type("L") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"L\") == true 💥\n");
	if (is_valid_element_type("pl") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"pl\") == true 💥\n");
	if (is_valid_element_type("sp") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"sp\") == true 💥\n");
	if (is_valid_element_type("cy") == true)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"cy\") == true 💥\n");
	if (is_valid_element_type("") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"\") == false 💥\n");
	if (is_valid_element_type(NULL) == false)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(NULL) == false 💥\n");
	if (is_valid_element_type("Pl") == false)
		counter++;
	else
		printf("ERROR: test_is_valid_element_type(\"Pl\") == false 💥\n");
	if (counter == total_tests)
		printf("✅\n");
	else
		printf("💥\n");
}