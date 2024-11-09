/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:33:49 by gcros             #+#    #+#             */
/*   Updated: 2024/11/06 16:05:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_manip.h"
#include "mlx_manip.h"
#include "libft.h"
#include "stdio.h"
#include "draw.h"

static void	cm_put_pixels(t_img_p canvas, t_color pixel,
				const int canvas_x, const int canvas_y);

void	cm_put_line(t_img_p canvas, restrict t_rc_event_p rc,
	const int canvas_x)
{
	const int		layer_x = rc->offset * rc->img->width;
	const int		beginning = \
			(int)(canvas->height + canvas->height / rc->dist) >> 1;
	const int		limit = ft_min(canvas->height, beginning);
	const double	ratio = rc->img->height * rc->dist / canvas->height;
	register int	i;

	i = canvas->height - limit;
	while (i < limit)
	{
		cm_put_pixels(canvas,
			rc->img->addr[(int)((i + beginning - canvas->height) * ratio)
			*rc->img->width + layer_x],
			canvas_x, i);
		i++;
	}
}

#if THICKNESS_RAYS == 1

static inline void	cm_put_pixels(t_img_p canvas, t_color pixel,
	const int canvas_x, const int canvas_y)
{
	canvas->addr[canvas_y * canvas->width + canvas_x] = pixel;
}

#else

static inline void	cm_put_pixels(t_img_p canvas, t_color pixel,
	const int canvas_x, const int canvas_y)
{
	size_t	i;

	i = 0;
	while (i < THICKNESS_RAYS)
	{
		canvas->addr[canvas_y * canvas->width + canvas_x + i] = pixel;
		i++;
	}
}

#endif
