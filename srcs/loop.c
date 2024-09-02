/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/09/02 20:48:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "cub_manip.h"
#include "math.h"
#include "put.h"
#include "mlx.h"

int	loop(t_loop_param *param)
{
	t_image_p	frac;
	t_image_p	img;
	static int	t = 0;
	int			i;

	frac = param->frac;
	img = param->img;
	if (t++ >= 10000)
		mlx_loop_end(param->mlx);
	i = 0;
	while (i < img->img.width)
	{
		cm_put_line(&img->img,
			&(t_rc_event){.img = &frac->img, .dist = 1, .offset = ((t % 1000) / 1000.)}, i);
		i += 2;
	}
	mm_img_display(&img->img, param->win, 0, 0);
	return (0);
}
