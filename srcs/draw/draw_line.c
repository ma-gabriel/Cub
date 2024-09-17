/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:20:31 by gcros             #+#    #+#             */
/*   Updated: 2024/09/17 17:49:44 by gcros            ###   ########.fr       */
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
(void) color;
	double a = (p1.y - p2.y) / (p1.x - p2.x);
	double b = - a * p1.x + p1.y;
	const double	stop = ft_minf(ft_minf(p2.y, img->height),
			img->width * a + b);
	y = ft_maxf(ft_maxf(p1.y, 0.), b);
	while (y < stop)
	{
		x = p1.x + (y - p1.y) * ratio;
		mm_img_putpixel(img, x, y, (t_color){.value = 0x00FF0000});
		y++;
	}
}

/*
static void	high(t_img *img, t_vec2 p1, t_vec2 p2, t_color color)
{
	const double	ratio = ((p2.x - p1.x) / (p2.y - p1.y));
	double			x;
	double			y;
(void) color;
	double a = (p1.y - p2.y) / (p1.x - p2.x);
	double b = - a * p1.x + p1.y;
	const double	stop = ft_minf(ft_minf(p2.x, img->width),
				(img->height - b) / a);
	y = ft_maxf(ft_maxf(p1.y, 0.), b);
	while (y < stop)
	{
		x = p1.x + (y - p1.y) * ratio;
		mm_img_putpixel(img, x, y, (t_color){.value = 0x00FF0000});
		y++;
	}
} */

static void	low(t_img *img, t_vec2 p1, t_vec2 p2, t_color color)
{
	const double	ratio = ((p2.y - p1.y) / (p2.x - p1.x));
	double			x;
	double			y;
(void) color;
	double a = (p1.y - p2.y) / (p1.x - p2.x);
	double b = - a * p1.x + p1.y;
	const double	stop = ft_minf(ft_minf(p2.x, img->width),
				(img->height - b) / a);
	
	x = ft_maxf(ft_maxf(p1.x, 0.), ((0 - b) / a));
	while (x < stop)
	{
		y = p1.y + (x - p1.x) * ratio;
		mm_img_putpixel(img, x, y, (t_color){.value = 0x000000FF});
		x++;
	}
}

void	draw_line(t_img *img, t_vec2 p1, t_vec2 p2, t_color color)
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
