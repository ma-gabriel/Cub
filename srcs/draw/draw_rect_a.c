/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:08:25 by gcros             #+#    #+#             */
/*   Updated: 2024/10/10 19:19:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "libft.h"
#include "draw.h"

void	draw_rect_a(t_img_p img, t_vec2 co, t_vec2 size, t_color color)
{
	int			i;
	int			j;
	const int	k = ft_min(co.x + size.x, img->width);
	const int	m = ft_min(co.y + size.y, img->height);

	i = ft_max(co.x, 0);
	while (i < k)
	{
		j = ft_max(co.y, 0);
		while (j < m)
		{
			draw_pixel_a(img, i, j, color);
			j++;
		}
		i++;
	}
}
