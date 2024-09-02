/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/09/03 01:23:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "cub_manip.h"
#include "math.h"
#include "put.h"
#include "mlx.h"

int	loop(t_loop_param *param)
{
	const t_img_p	frac = param->frac;
	const t_img_p	img = param->img;
	static int		t = 0;
	int				i;

	if (t++ >= 10000)
		mlx_loop_end(param->mlx);
	i = 0;
	while (i < img->width)
	{
		cm_put_line(img,
			&(t_rc_event){.img = frac,
			.dist = 1,
			.offset = i / (double)img->width}, i);
		i += 2;
	}
	mm_img_display(img, param->win, 0, 0);
	mm_img_display(frac, param->win, 1000, 0);
	return (0);
}
