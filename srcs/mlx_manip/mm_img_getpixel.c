/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_getpixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:21:00 by gcros             #+#    #+#             */
/*   Updated: 2024/09/03 01:06:13 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

inline t_color	mm_img_getpixel(register t_img_p img,
	register int x,
	register int y)
{
	return (img->addr[y * img->width + x]);
}

inline t_color	mm_img_getpixel_s(register t_img_p img,
	register int x,
	register int y)
{
	if ((x < 0) + (x >= img->width) + (y < 0) + \
		(y >= img->height))
		return ((t_color){0});
	return (mm_img_getpixel(img, x, y));
}