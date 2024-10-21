/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:33:49 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 18:08:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_manip.h"
#include "mlx_manip.h"
#include "libft.h"
#include "stdio.h"
#include "draw.h"

void	cm_put_line(t_img_p canvas, t_rc_event_p rc, int canvas_x)
{
	const int		layer_x = rc->offset * rc->img->width;
	const int		beginning = (canvas->height + canvas->height / rc->dist) / 2;
	const int		limit = ft_min(canvas->height, beginning);
	const double	ratio = (double) (rc->img->height) * rc->dist / (double) canvas->height;
	int				i;

	i = canvas->height - limit;
	while (i < limit)
	{
		mm_img_putpixel(canvas, canvas_x, i,
			mm_img_getpixel(rc->img, layer_x, (i + beginning - canvas->height) * ratio));
		i++;
	}
}
