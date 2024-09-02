/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:58:59 by gcros             #+#    #+#             */
/*   Updated: 2024/08/21 21:42:22 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"
#include <stdlib.h>
#include "put.h"

t_img_p	mm_img_new(t_mlx_p mlx, int width, int height)
{
	t_img_p	img;

	img = malloc(sizeof(*img));
	if (img == NULL)
	{
		ft_putendl_fd("mm_img_new: malloc: NULL pointer returned", 2);
		return (NULL);
	}
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
	{
		ft_putendl_fd("mm_img_init: mlx_new_image: NULL pointer returned", 2);
		return (1);
	}
	img_p->addr = (t_color *)mlx_get_data_addr(img_p->img_ptr,
			&img_p->bits_per_pixel, &img_p->size_line, &img_p->endian);
	if (img_p->addr == NULL)
	{
		ft_putendl_fd("mm_img_init: mlx_get_data_addr: how", 2);
		mlx_destroy_image(mlx, img_p->img_ptr);
		return (1);
	}
	img_p->height = height;
	img_p->width = width;
	return (0);
}