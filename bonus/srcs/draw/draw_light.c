/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:57:54 by gcros             #+#    #+#             */
/*   Updated: 2024/11/21 15:30:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "mlx_manip.h"
#include "struct.h"
#include "draw.h"
#include <math.h>
#include "libft.h"
#include "flashlight.h"

static inline double	dist(t_vec2 v1, t_vec2 v2)
{
	return (hypot(v2.x - v1.x, v2.y - v1.y));
}

void	draw_light(t_flashlight flashlight, t_img_p img)
{
	int					i;
	int					j;
	const t_vec2		r_center = (t_vec2){flashlight.center.x * img->width, flashlight.center.y * img->height};
	const double		r_size = flashlight.size * img->width;
	t_color				color;

	j = 0;
	color = (t_color){.r = 0, .g = 0, .b = 0};
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			if (dist(r_center, (t_vec2){i, j}) <= r_size)
				color.a = (1 - dist(r_center, (t_vec2){i, j}) / r_size) * (255 - flashlight.max_a) + flashlight.max_a;
			else
				color.a = flashlight.max_a;
			draw_pixel_a(img, i, j, color);
			i++;
		}
		j++;
	}
}
