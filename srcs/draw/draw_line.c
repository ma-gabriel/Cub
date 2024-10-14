/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:20:31 by gcros             #+#    #+#             */
/*   Updated: 2024/10/10 19:11:38 by gcros            ###   ########.fr       */
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


// don't work
//void	draw_line(t_img_p img, t_vec2 p1, t_vec2 p2, t_color color)
//{
//	const t_vec2	dp = {.x = p2.x - p1.x, .y = p2.y - p1.y};
//	t_vec2			p;
//	int				i;

//	p = p1;
//	i = 2. * dp.y - dp.x;
//	while (p.x < p2.x)
//	{
//		mm_img_putpixel_s(img, p.x, p.y, color);
//		printf("{.x = %f, .y = %f}\n", p.x, p.y);
//		if (i >= 0)
//		{
//			p.y++;
//			i += 2. * dp.y - 2. * dp.x;
//		}
//		else
//		{
//			i += 2. * dp.y;
//		}
//		p.x++;
//	}
//}
