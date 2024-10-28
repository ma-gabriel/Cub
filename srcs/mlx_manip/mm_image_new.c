/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_image_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:48:06 by gcros             #+#    #+#             */
/*   Updated: 2024/10/28 21:20:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"
#include "put.h"
#include <stdlib.h>
#include "defines.h"

int	mm_image_init(t_image_p img, t_mlx_p mlx, int width, int height)
{
	img->mlx_ptr = mlx;
	if (mm_img_init(&img->img, mlx, width, height))
		return (1);
	return (0);
}

t_image_p	mm_image_new(t_mlx_p mlx, int width, int height)
{
	t_image_p	img;

	img = malloc(sizeof(*img));
	if (img == NULL)
	{
		ft_putendl_fd(ERR"mm_image_new: malloc: NULL pointer returned", 2);
		return (NULL);
	}
	if (mm_image_init(img, mlx, width, height))
	{
		free(img);
		return (NULL);
	}
	return (img);
}
