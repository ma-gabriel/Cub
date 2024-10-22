/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_to_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:19:56 by gcros             #+#    #+#             */
/*   Updated: 2024/10/22 18:10:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "draw.h"
#include "num.h"

void	mm_img_to_img(t_img_p src, t_img_p dest, int x, int y)
{
	const int	h = ft_min(src->height, dest->height - y);
	const int	w = ft_min(src->width, dest->width - x);
	int			i;
	int			j;

	j = ft_max(0, -y);
	while (j < h)
	{
		i = ft_max(0, -x);
		while (i < w)
		{
			draw_pixel_a(dest, x + i ,y + j, mm_img_getpixel(src, i, j));
			i++;
		}
		j++;
	}
}
