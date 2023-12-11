#include "../../includes/miniRT.h"

unsigned int	get_color(t_color *rgb)
{
	unsigned int	c;

	// if (rgb->bright == 0)
	// 	return (0);
	c = 0;
	if (rgb->b > 255)
		c = c + 255;
	else
		c = c + rgb->b;
	if (rgb->g > 255)
		c = c + 0x00000100 * 255;
	else
		c = c + 0x00000100 * rgb->g;
	if (rgb->r > 255)
		c = c + 0x00010000 * 255;
	else
		c = c + 0x00010000 * rgb->r;
	if (rgb->bright > 255)
		c = c + 0x01000000 * 255;
	else
		c = c + 0x01000000 * rgb->bright;
	return (c);
}

t_color	color_mix(t_color *a, t_color *b)
{
	t_color	re;

	re.b = a->b + b->b;
	re.g = a->g + b->g;
	re.r = a->r + b->r;
	re.bright = a->bright + b->bright;
	if (re.bright > 255)
		re.bright = 255;
	return (re);
}

t_color	color_reflect(t_color *a, t_color *b)
{
	t_color	re;

	re.b = a->b * b->b / 255;
	re.g = a->g * b->g / 255;
	re.r = a->r * b->r / 255;
	return (re);
}
