/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/09/02 16:57:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "cub_manip.h"
#include "math.h"
#include "put.h"
#include "mlx.h"

int	loop(t_loop_param *param)
{
	int			i;
	int			j;
	t_image		*image;
	static int	t = 0;

	image = param->img;
	if (t++ >= 10)
		mlx_loop_end(param->mlx);
	cm_set_sky(&image->img, (t_color){0X000000FF});
	cm_set_ground(&image->img, (t_color){0X00FF0000});
	mm_img_display(&image->img, param->win, 0, 0);
	return (0);
}
