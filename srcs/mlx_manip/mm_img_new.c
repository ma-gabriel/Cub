/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:58:59 by gcros             #+#    #+#             */
/*   Updated: 2024/10/28 21:20:26 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"
#include <stdlib.h>
#include "put.h"
#include "defines.h"

t_img_p	mm_img_new(t_mlx_p mlx, int width, int height)
{
	t_img_p	img;

	img = malloc(sizeof(*img));
	if (img == NULL)
		return (NULL);
	if (mm_img_init(img, mlx, width, height))
	{
		free(img);
		return (NULL);
	}
	return (img);
}

int	mm_img_init(t_img_p img_p, t_mlx_p mlx, int width, int height)
{
	img_p->img_ptr = mlx_new_image(mlx, width, height);
	if (img_p->img_ptr == NULL)
		return (1);
	img_p->addr = (t_color *)mlx_get_data_addr(img_p->img_ptr,
			&img_p->bits_per_pixel, &img_p->size_line, &img_p->endian);
	if (img_p->addr == NULL)
	{
		mlx_destroy_image(mlx, img_p->img_ptr);
		return (1);
	}
	img_p->height = height;
	img_p->width = width;
	return (0);
}

t_img_p	mm_file_to_img_new(t_mlx_p mlx, char *file)
{
	t_img_p	img;

	img = malloc(sizeof(*img));
	if (img == NULL)
		return (NULL);
	if (mm_file_to_img_init(img, mlx, file))
	{
		free(img);
		return (NULL);
	}
	return (img);
}

int	mm_file_to_img_init(t_img_p img_p, t_mlx_p mlx, char *file)
{
	img_p->img_ptr = mlx_xpm_file_to_image(mlx, file,
			&(img_p->width), &(img_p->height));
	if (img_p->img_ptr == NULL)
		return (1);
	img_p->addr = (t_color *) mlx_get_data_addr(img_p->img_ptr,
			&img_p->bits_per_pixel, &img_p->size_line, &img_p->endian);
	if (img_p->addr == NULL)
	{
		mlx_destroy_image(mlx, img_p->img_ptr);
		return (1);
	}
	return (0);
}
