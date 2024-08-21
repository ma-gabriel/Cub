/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/08/21 21:39:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "math.h"
#include "put.h"
#include "mlx.h"

int t = 0;

int	loop(t_loop_param *param)
{
	int	i;
	int	j;

	if (t++ >= 10000)
		mlx_loop_end(param->mlx);
	i = param->img->img.width;
	while (i-- > 0)
	{
		j = param->img->img.height;
		while (j-- > 0)
		{
			mm_img_putpixel(&param->img->img, i, j,
				mm_get_color(0, (i + j), (i - j + t), ((i + t) ^ j)));
		}
	}
	mm_img_display(&param->img->img, param->win, 0, 0);
	return (0);
}
