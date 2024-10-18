/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:52:49 by gcros             #+#    #+#             */
/*   Updated: 2024/10/17 17:04:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx_manip.h"

void	draw_pixel_a(register t_img_p img,
	register int x,
	register int y,
	register t_color color)
{
	const t_color	old = mm_img_getpixel(img, x, y);
	const t_color	n = color_blend(color, old);

	img->addr[y * img->width + x] = n;
}

void	draw_pixel_as(register t_img_p img,
	register int x,
	register int y,
	register t_color color)
{
	if ((x < 0)
		+ (x >= img->width)
		+ (y < 0)
		+ (y >= img->height))
		return ;
	draw_pixel_a(img, x, y, color);
}
