/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:24:22 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/08 07:20:56 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	parsing_tests(void)
{
	test_is_valid_file_extension();
	test_is_valid_file();
	test_get_integer_part();
	test_get_float_part();
	test_is_valid_float_number();
	test_ft_atof();
	test_is_valid_element_type();
	test_split_len();
	test_validate_element_a();
	test_validate_element_l();
	test_validate_element_c();
	test_validate_rgb();
}