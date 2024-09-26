/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:59:24 by gcros             #+#    #+#             */
/*   Updated: 2024/09/26 23:24:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "libft.h"
#include "math.h"

void	draw_rect(t_img_p img, t_vec2 co, t_vec2 size, t_color color)
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
			mm_img_putpixel(img, i, j, color);
			j++;
		}
		i++;
	}
}
