/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:57:54 by gcros             #+#    #+#             */
/*   Updated: 2024/11/20 21:04:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "draw.h"
#include <math.h>
#include "libft.h"

static inline double	dist(t_vec2 v1, t_vec2 v2)
{
	return (hypot(v2.x - v1.x, v2.y - v1.y));
}

void	draw_light(t_img_p img, t_vec2 center, int size)
{
	const unsigned char	min_color = 20;
	int					i;
	int					j;
	t_color				color;

	j = 0;
	color = (t_color){.r = 0, .g = 0, .b = 0};
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			if (dist(center, (t_vec2){i, j}) <= size)
				color.a = (1 - dist(center, (t_vec2){i, j}) / (double)size) * (255 - min_color) + min_color;
			else
				color.a = min_color;
			draw_pixel_a(img, i, j, color);
			i++;
		}
		j++;
	}
}
