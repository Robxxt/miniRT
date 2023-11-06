/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:24:22 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/06 05:30:48 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	parsing_tests(void)
{
	test_is_valid_file_extension();
	test_is_valid_file();
	test_ft_atof();
	test_is_valid_number();
}