/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:20:29 by gcros             #+#    #+#             */
/*   Updated: 2024/10/22 18:37:46 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "draw.h"

void	draw_cross(t_img_p img)
{
	const t_vec2	mid = {img->width * .5, img->height * .5};
	const int		size = img->height * 0.02;
	int				i;
	const t_color	c = {.value = ((~mm_img_getpixel(img, mid.x, mid.y).value)
			& 0xffffff) | 0x0f000000};

	i = -1;
	while (i < 2)
	{
		draw_line_a(img, (t_vec2){mid.x - size, mid.y + i},
			(t_vec2){mid.x + size, mid.y + i},
			c);
		draw_line_a(img, (t_vec2){mid.x + i, mid.y - size},
			(t_vec2){mid.x + i, mid.y + size},
			c);
		i++;
	}
}
