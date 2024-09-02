/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel-get_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/08/21 18:20:18 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "math.h"
#include "put.h"
#include "mlx.h"

int t = 0;

int	loop(t_loop_param *param)
{
	int i;
	int j;

	if (t++ >= 10000)
		mlx_loop_end(param->mlx);
	i = param->img->img.width;
	while (i-- > 0)
	{
		j = param->img->img.height;
		while (j-- > 0)
		{
			mm_img_putpixel(&param->img->img, i, j,
				mm_get_color(0, (i + j), (i - (j + t)), ((i + t) ^ j)));
		}
	}
	mm_img_display(&param->img->img, param->win, 0, 0);
	return (0);
}

int	main(void)
{
	t_mlx_p			mlx;
	t_window_p		win;
	t_image_p		img;
	t_loop_param	lparam;

	mlx = mm_mlx_new();
	win = mm_window_new(mlx, 1000, 600, "test");
	img = mm_image_new(mlx, 1000, 600);
	lparam = (t_loop_param){.mlx = mlx, .img = img, .win = win};
	mlx_loop_hook(mlx, loop, &lparam);
	mlx_loop(mlx);
	mm_image_delete(img);
	mm_window_delete(win);
	mm_mlx_delete(mlx);
}
