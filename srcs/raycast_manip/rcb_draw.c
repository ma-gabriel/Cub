/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:31:41 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 17:33:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_manip.h"
#include "cub_manip.h"
#include "mlx_manip.h"
#include "stdio.h"
#include "math.h"

void	rcb_draw(t_rc_buf_p rcb, t_img_p img)
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
