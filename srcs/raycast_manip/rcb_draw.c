/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:31:41 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 22:27:47 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_manip.h"
#include "cub_manip.h"
#include "mlx_manip.h"
#include "stdio.h"
#include "math.h"

void	rcb_display(t_rc_buf_p rcb, t_img_p img)
{
	const double	ratio = ((double)img->width / (double)rcb->size);
	double			i;
	t_rc_event_p	rc;

	i = 0;
	while ((size_t)floor(i) < rcb->size)
	{
		rc = &rcb->buf[(int)floor(i)],
		cm_put_line(img, rc, i);
		i += ratio;
	}
}

void	rcb_draw(t_rc_buf_p rcb, t_img_p img, t_map_p map)
{
	size_t			i;
	const t_vec2	ratio = (t_vec2){img->width / (double)map->width,
		img->height / (double)map->height};
	t_vec2			tmp;
	t_vec2			c;
	
	i = 0;
	while (i < rcb->size)
	{
		tmp = (t_vec2){(rcb->buf[i].collision.x) * ratio.x,
			(rcb->buf[i].collision.y) * ratio.y};
		c = (t_vec2){(rcb->buf[i].start.x) * ratio.x,
			(rcb->buf[i].start.y) * ratio.y};
		draw_line(img, c, tmp, (t_color){.value = 0x0000FF00});
		i++;
	}
}
