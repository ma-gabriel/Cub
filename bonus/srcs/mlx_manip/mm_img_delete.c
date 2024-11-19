/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:59:01 by gcros             #+#    #+#             */
/*   Updated: 2024/08/20 21:00:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"
#include <stdlib.h>

void	mm_img_delete(t_img_p img, t_mlx_p mlx)
{
	mm_img_destroy(img, mlx);
	free(img);
}

void	mm_img_destroy(t_img_p img, t_mlx_p mlx)
{
	mlx_destroy_image(mlx, img->img_ptr);
}
