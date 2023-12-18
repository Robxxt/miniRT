/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:36:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/18 11:16:29 by rdragan          ###   ########.fr       */
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

# include "../mlx/mlx.h"

typedef struct s_color
{
	unsigned int	bright;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_color;
typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;
typedef struct s_line
{
	t_vector	pos;
	t_vector	nv;
}	t_line;

typedef struct s_cub
{
	bool		exists;
	t_vector	pos;
	t_vector	nv1;
	t_vector	nv2;
	float		size;
	t_line		side[7];
	t_color		rgb;
	char		texture;
}	t_cub;

typedef struct s_amount
{
	int lit;
	int	pl;
	int	sp;
	int	cy;
	int	cb;
}	t_amount;


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
	int		fv;
}	t_camara;

/*
pos: coordinates of the light point => input: [x, y, z]
lb: Light brightness ratio => range: [0.0, 1.0]
[OPTIONAL] rgb: color representation of the light => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_light
{
	float	pos[3];
	float	lb;
	int		rgb[3];
}	t_light;

/*
pos: coordinates of the light point => input: [x, y, z]
d: Sphere diameter 
rgb: color representation => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_sphere
{
	bool	exists;
	float	pos[3];
	float	d;
	int		rgb[3];
	char	texture;
}	t_sphere;

/*
pos: coordinates of the light point => input: [x, y, z]
nv: 3d Normalized vector => range: [-1, 1] => input: [x, y, z]
rgb: color representation => [red, green, blue] => color range: [0, 255]
*/
typedef	struct s_plane
{
	bool	exists;
	float	pos[3];
	float	nv[3];
	int		rgb[3];
	char	texture;
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
	bool	exists;
	float	pos[3];
	float	nv[3];
	float	d;
	float	h;
	int		rgb[3];
	char	texture;
}	t_cylinder;

typedef	struct s_image
{
	t_ambient	ambient;
	t_camara	camara;
	t_light		light[17];
	t_sphere	sphere[9];
	t_plane		plane[9];
	t_cylinder	cylinder[9];
	t_cub		cube[9];
	t_amount	amount;
}	t_image;

/*
**minilibx vars
*/
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		edn;
	t_image	*objs;
}	t_vars;

typedef struct s_pixel
{
	int		x;
	int		y;
}	t_pixel;

/*
** 3D objects
*/

# define DEG_RAD 0.0174532925f

typedef struct s_surface
{
	t_vector	pos;
	t_vector	nv;
	t_color		rgb;
	char		texture;
}	t_surface;

typedef	struct s_ambt
{
	t_color	rgb;
}	t_ambt;

typedef struct s_panel
{
	bool		exists;
	t_vector	pos;
	t_vector	nv;
	t_color		rgb;
	char		texture;
}	t_panel;

typedef struct s_ray
{
	t_vector	pos;
	t_vector	nv;
	bool		end;
	t_color		rgb;
}	t_ray;

typedef struct s_circle
{
	t_vector	pos;
	t_vector	nv;
	float		radii;
}	t_circle;

typedef struct s_sp
{
	bool		exists;
	t_vector	pos;
	float		radii;
	t_color		rgb;
	char		texture;
}	t_sp;

typedef struct s_cylind
{
	bool		exists;
	t_vector	pos;
	t_vector	nv;
	float		radii;
	t_circle	up;
	t_circle	down;
	t_color		rgb;
	char		texture;
	float		height;
}	t_cylind;

typedef	struct s_lit
{
	t_vector	pos;
	t_color		rgb;
}	t_lit;

typedef	struct s_cmr
{
	t_vector	pos;
	t_vector	nv;
	int		fv;
}	t_cmr;

typedef struct	s_space
{
	t_ambt		ambient;
	t_cmr		cmr;
	t_lit		lit[17];
	t_sp		sp[9];
	t_panel		pl[9];
	t_cylind	cylind[9];
	t_cub		cub[9];
	t_amount	amount;
}	t_space;

/*
** rendering resolution
*/

# define SCREEN_X 1920
# define SCREEN_Y 1200
# define ASP_RATIO 1.6f
# define RASP_RATIO 0.625f

// Vector

float	module2(t_vector *a);
float	module(t_vector *a);
t_vector	normized(t_vector a);
t_vector	v_product(t_vector *a, float b);
t_vector	v_plus(t_vector *a, t_vector *b);
t_vector	v_minus(t_vector *a, t_vector *b);
float	dot_product(t_vector *a, t_vector *b);
t_vector	cross_product(t_vector *a, t_vector *b);

float	distance2(t_vector *a, t_vector *b);
float	distance(t_vector *a, t_vector *b);

// color
void	paint_pixel(t_vars *vars, t_pixel pos, int color);
t_color	color_reflect(t_color *a, t_color *b);
t_color	color_mix(t_color *a, t_color *b);
unsigned int	get_color(t_color *rgb);
t_color	color_normized(t_color *a, unsigned int n);
// t_color	color_normized(t_color *a, unsigned int n, int i);

// tracing
t_ray	camera_ray(t_cmr *cmr, t_pixel *pix);
t_surface	trace_pl(t_panel *pl, t_ray *ray);
t_surface	trace_sp(t_sp *sp, t_ray *ray);
t_surface	trace_cyl(t_cylind *cylind, t_ray *ray);
t_surface	trace_cub(t_cub *cub, t_ray *ray);
t_color		trace_rays(t_space *space, t_ray ray, int i);

// solve function
float	delta(float a, float b, float c);
float	root_minus(float a, float b, float c);
float	root_plus(float a, float b, float c);
float	min_root(float a, float b, float c);

// Validate functions
bool	is_valid_file_extension(char *filename);
bool	is_valid_file(char *filename);
bool	is_valid_float_number(char *str);
bool	is_valid_element_type(char *type);
bool	validate_rgb(char *s);
bool	validate_coord(char *s);
bool	validate_element_a(char **s);
bool	validate_element_l(char **s);
bool	validate_element_c(char **s);
bool	has_valid_content(t_list *lst);
bool	is_valid_angle(int d);
bool	is_valid_int_list(char **list, bool (*function)(char *, int));
bool	is_valid_float_list(char **list, bool (*function)(char *, float));
bool	validate_coord(char *s);
bool	validate_3d_normalized_vector(char *s);
bool	validate_sp(char **s);
bool	validate_pl(char **s);
bool	validate_cy(char **s);
bool	validate_cb(char **s);
bool	is_valid_texture(char *s, int type);

int		get_integer_part(char *str);
float	get_float_part(char *str);
float	ft_atof(char *str);
t_list	*get_file_content(int fd);
int		split_len(char **s);

t_image	*parser(char **argv);
void	init_amount(t_amount* a);
void	read_int_list(int *list, char *s);
void	read_float_list(float *list, char *s);
void	populate_context_elements(t_image *image, char **node_content, int node_type);
void	populate_objects(t_image *image, char **node_content, int node_type);


void	clear_lst(t_list *lst);

// Debugging info
void	print_lst(t_list *lst);
void	print_color(t_color color);
void	print_vector(t_vector vector, char *s);
void	print_panel(t_panel panel);
void	print_space(t_space s);

#endif