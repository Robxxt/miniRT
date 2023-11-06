/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:24:22 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/06 06:49:08 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	parsing_tests(void)
{
	test_is_valid_file_extension();
	test_is_valid_file();
	test_get_integer_part();
	test_get_float_part();
	test_is_valid_number();
	test_ft_atof();
}