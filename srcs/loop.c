/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/08/21 14:54:27 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "math.h"
#include "put.h"

int	loop(t_loop_param *param)
{
	for(int i = 0; i < param->img->img.width; i++)
		for(int j = 0; j < param->img->img.height; j++)
			mm_img_putpixel_s(&param->img->img, i, j, mm_get_color(0, i + j, i * j, i ^ j));
	mm_img_display(&param->img->img, param->win, 0, 0);
	return (0);
}
