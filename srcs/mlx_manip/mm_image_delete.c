/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_image_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:48:18 by gcros             #+#    #+#             */
/*   Updated: 2024/08/20 20:05:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"
#include <stdlib.h>

void	mm_image_delete(t_image_p img)
{
	mlx_destroy_image(img->mlx_ptr, img->img.img_ptr);
	free(img);
}

void	mm_img_destroy(t_mlx_p mlx, t_img img)
{
	mlx_destroy_image(mlx, img.img_ptr);
}
