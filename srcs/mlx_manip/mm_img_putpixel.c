/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_putpixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:28:03 by gcros             #+#    #+#             */
/*   Updated: 2024/10/17 17:08:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_manip.h"

inline void	mm_img_putpixel(register t_img_p img,
	register int x,
	register int y,
	register t_color color)
{
	img->addr[y * img->width + x] = color;
}

inline void	mm_img_putpixel_s(register t_img_p img,
	register int x,
	register int y,
	register t_color color)
{
	if ((x < 0)
		+ (x >= img->width)
		+ (y < 0)
		+ (y >= img->height))
		return ;
	img->addr[y * img->width + x] = color;
}
