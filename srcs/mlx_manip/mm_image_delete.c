/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_image_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:48:18 by gcros             #+#    #+#             */
/*   Updated: 2024/08/20 21:14:54 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"
#include <stdlib.h>

void	mm_image_delete(t_image_p img)
{
	mm_image_destroy(img);
	free(img);
}

void	mm_image_destroy(t_image_p img)
{
	mm_img_destroy(&img->img, img->mlx_ptr);
}
