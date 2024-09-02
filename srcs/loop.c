/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/08/22 17:30:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
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
	i = image->img.width;
	while (i-- > 0)
	{
		j = image->img.height;
		while (j-- > 0)
		{
			mm_img_putpixel(&image->img, i, j,
				mm_get_color(0, ((cos(i) * 50.) - (sin(j) * 50.)) + t, (i + j + t), (((i - t) ^ j) ^ t)));
		}
	}
	mm_img_display(&image->img, param->win, 0, 0);
	return (0);
}
