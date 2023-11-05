/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:36:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/05 08:25:11 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h> // To remove!!!

// Validate file extension
bool	is_valid_file_extension(char *filename);
bool	is_valid_file(char *filename);

// Tests
void	test_is_valid_file_extension(void);
void	test_is_valid_file(void);
void	parsing_tests(void);

#endif