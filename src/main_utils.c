/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiqin <tiqin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:57:39 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/20 13:06:13 by tiqin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"
#include "../includes/api.h"

/*
Checks that the program has received a valid argument
containing the filename with the map.
*/
bool	init_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("ERROR: Missing the image file!\n", STDERR_FILENO);
		return (false);
	}
	if (is_valid_file(argv[1]) == false)
	{
		ft_putstr_fd("ERROR: Invalid File!\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}

/*
Goes through the link list freeing each node content.
After frees the list itself.
*/
void	clear_lst(t_list *lst)
{
	ft_lstclear(&lst);
	free(lst);
}

bool	check_vectors(t_image *image)
{
	if (image_has_valid_vectors(image) == false)
	{
		free(image);
		ft_putstr_fd("ERROR: There's an invalid vector!\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}

void	set_cube(t_cub *cub)
{
	t_vector	tmp;
	int			i;

	cub->side[3].nv = cub->nv1;
	cub->side[4].nv = v_product(&cub->nv1, -1.0f);
	cub->side[5].nv = cub->nv2;
	cub->side[2].nv = v_product(&cub->nv2, -1.0f);
	cub->side[1].nv = cross_product(&cub->nv1, &cub->nv2);
	cub->side[6].nv = v_product(&cub->side[1].nv, -1.0f);
	i = 1;
	while (i < 7)
	{
		tmp = v_product(&cub->side[i].nv, 0.5f * cub->size);
		cub->side[i].pos = v_plus(&cub->pos, &tmp);
		i++;
	}
}

void	set_cyd(t_cylind *cyd)
{
	t_vector	tmp;

	cyd->up.nv = cyd->nv;
	cyd->down.nv = v_product(&cyd->nv, -1.0f);
	tmp = v_product(&cyd->nv, cyd->height * 0.5f);
	cyd->up.pos = v_plus(&cyd->pos, &tmp);
	cyd->down.pos = v_minus(&cyd->pos, &tmp);
	cyd->up.radii = cyd->radii;
	cyd->down.radii = cyd->radii;
}
