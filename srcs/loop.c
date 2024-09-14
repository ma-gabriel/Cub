/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/09/13 16:54:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "cub_manip.h"
#include "math.h"
#include "put.h"
#include "mlx.h"
#include "draw.h"

int	benchmark_1(t_loop_param *param, int t);

int	loop(t_loop_param *param)
{
	static int		t = 0;

	kb_mouse_update(param->win, param->kbe);
	if (t++ >= 10000 || param->kbe->esc)
		mlx_loop_end(param->mlx);
	//mm_img_display(param->img, param->win, 0, 0);
	benchmark_1(param, t);
	return (0);
}

int	benchmark_1(t_loop_param *param, int t)
{
	const t_img_p	frac = param->frac;
	const t_img_p	img = param->img;
	int				i;
	int				j;

	(void) t;
	j = 0;
	(void) j;
	//mm_img_set_bg(img, (t_color){.value = 0x0});
	while (j < frac->height)
	{
		i = 0;
		while (i < frac->width)
		{
			if (param->kbe->mouse[1])
				mm_img_putpixel(frac, i, j,
					(t_color){.r = (i << 2) - param->kbe->mouse_x, .b = (j << 2) - param->kbe->mouse_y, .g = 0});
			else
				mm_img_putpixel(frac, i, j,
					(t_color){.r = i + (t >> 2), .b = i + (t >> 1), .g = 0});
			i += 1;
		}
		j += 1;
	}
	draw_rect(frac,
		(t_vec2){0, (t / 10) % frac->height},
		(t_vec2){frac->width, 20}, (t_color){.value = 0x00FFFFFF});

	i = 0;
	while (i < 100)
	{
		cm_put_line(img,
			&(t_rc_event){.img = frac,
			.dist = (double)(i / 100.) + 1.,
			.offset = (double)(i / 100.)}, i + 900.);
		i += 1;
	}
	mm_img_display(img, param->win, 0, 0);
	mm_img_display(frac, param->win, 1000, 0);
	return (0);
}

/*	test fisheye
		cm_put_line(img,
			&(t_rc_event){.img = frac,
			.dist = (i / 100.) + 1,
			.offset = (i / 100.)}, i + 100);
*/