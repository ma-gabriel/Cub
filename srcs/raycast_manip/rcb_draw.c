/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:31:41 by gcros             #+#    #+#             */
/*   Updated: 2024/10/16 18:48:08 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_manip.h"
#include "cub_manip.h"
#include "mlx_manip.h"

void	rcb_draw(t_rc_buf_p rcb, t_img_p img)
{
	const double	ratio = ((double)img->width / (double)rcb->size);
	double			i;

	i = 0;
	while (i < rcb->size)
	{
		cm_put_line(img, &rcb->buf[(size_t)i], i);
		i += ratio;
	}
}
