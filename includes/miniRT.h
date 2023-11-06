/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:36:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/06 07:58:19 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h> // To remove!!!

/*
r: Lighting ratio => range: [0.0, 1.0]
rgb: color representation => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_ambient
{
	float	r;
	int		rgb[3];
}	t_ambient;

/*
pos: coordinates of the view point => input: [x, y, z]
nv: 3d Normalized vector => range: [-1, 1] => input: [x, y, z]
fv: Horizontal field of view in degrees => range: [0, 180]
*/
typedef	struct s_camara
{
	float	pos[3];
	float	nv[3];
	int		fv[3];
}	t_camara;

/*
pos: coordinates of the light point => input: [x, y, z]
lb: Light brightness ratio => range: [0.0, 1.0]
[OPTIONAL] rgb: color representation of the light => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_light
{
	float	pos[3];
	float	lb[3];
	int		rgb[3];
}	t_light;

/*
pos: coordinates of the light point => input: [x, y, z]
d: Sphere diameter 
rgb: color representation => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_sphere
{
	float	pos[3];
	float	d;
	int		rgb[3];
}	t_sphere;

/*
pos: coordinates of the light point => input: [x, y, z]
nv: 3d Normalized vector => range: [-1, 1] => input: [x, y, z]
rgb: color representation => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_plane
{
	float	pos[3];
	float	nv[3];
	int		rgb[3];
}	t_plane;

/*
pos: coordinates of the light point => input: [x, y, z]
nv: 3d Normalized vector => range: [-1, 1] => input: [x, y, z]
d: Cylinder diameter
h: Cylinder diameter
rgb: color representation => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_cylinder
{
	float	pos[3];
	float	nv[3];
	float	d;
	float	h;
	int		rgb[3];
}	t_cylinder;

typedef	struct s_image
{
	t_ambient	ambient;
	t_camara	camara;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_image;


// Validate functions
bool	is_valid_file_extension(char *filename);
bool	is_valid_file(char *filename);
bool	is_valid_number(char *str);

int		get_integer_part(char *str);
float	get_float_part(char *str);
float	ft_atof(char *str);

// Tests
void	parsing_tests(void);
void	test_is_valid_file_extension(void);
void	test_is_valid_file(void);
void	test_ft_atof(void);
void	test_get_integer_part(void);
void	test_is_valid_number(void);
void	test_get_float_part(void);


#endif