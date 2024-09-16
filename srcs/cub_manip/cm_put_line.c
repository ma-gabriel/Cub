/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:33:49 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 16:23:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_manip.h"
#include "mlx_manip.h"
#include "libft.h"
#include "stdio.h"

/*
void	cm_put_line(t_img_p img, t_rc_event_p rc, int x)
{
	const t_img_p	rimg = rc->img;
	const int		o = rc->offset * rimg->width;
	const double	p = rimg->height / (double)img->height;
	int				i;

	const int y = img->height / 2; // la valeur ou i est a la moitie

	rc->dist = 2;
	i = img->height / (double) (rc->dist * 4) + y ;
	const int temp = i ; // la valeur ou i doit s'arreter
	while (i-- > -temp + 2 * y)
	{
		mm_img_putpixel_s(img, x, i,
			mm_img_getpixel_s(rimg, o, i * p));
	}
} */

void	cm_put_line(t_img_p img, t_rc_event_p rc, int x)
{
	const t_img_p	rimg = rc->img;
	const int		o = rc->offset * rimg->width;

	const int	half = img->height >> 1; // la valeur ou i est a la moitie
	int	high = (int) (half / (double) rc->dist) >> 1;
	const double	p = 1 / (double)(half);
	int				i;

	i = high + half;
	double	ip = (i * p - 1. + high * p) * rimg->height * (double) rc->dist;
	double		remove = p * (double) rimg->height * rc->dist;
	if (high > half)
	{
		i = img->height;
		ip = (i * p - 1. + high * p) * rimg->height * (double) rc->dist;
		high = half;
	}
	while (i-- > half - high)
	{
		mm_img_putpixel_s(img, x, i,
			mm_img_getpixel_s(rimg, o, ip));
		ip -= remove;
	}
}