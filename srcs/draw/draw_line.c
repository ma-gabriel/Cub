/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:20:31 by gcros             #+#    #+#             */
/*   Updated: 2024/10/20 17:58:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "libft.h"

static void	high(t_img *img, t_vec2 p1, t_vec2 p2, t_color color)
{
	const double	ratio = ((p2.x - p1.x) / (p2.y - p1.y));
	double			x;
	double			y;
	const double	stop = ft_minf(p2.y, img->height);

	y = ft_maxf(p1.y, 0.);
	(void) color;
	while (y < stop)
	{
		x = p1.x + (y - p1.y) * ratio;
		mm_img_putpixel_s(img, x, y, color);
		y++;
	}
}

static void	low(t_img *img, t_vec2 p1, t_vec2 p2, t_color color)
{
	const double	ratio = ((p2.y - p1.y) / (p2.x - p1.x));
	double			x;
	double			y;
	const double	stop = ft_minf(p2.x, img->width);

	(void) color;
	x = ft_maxf(p1.x, 0.);
	while (x < stop)
	{
		y = p1.y + (x - p1.x) * ratio;
		mm_img_putpixel_s(img, x, y, color);
		x++;
	}
}

void	draw_line(t_img_p img, t_vec2 p1, t_vec2 p2, t_color color)
{
	if (ft_absf(p2.y - p1.y) < ft_absf(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			low(img, p2, p1, color);
		else
			low(img, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			high(img, p2, p1, color);
		else
			high(img, p1, p2, color);
	}
}
