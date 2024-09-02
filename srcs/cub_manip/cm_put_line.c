/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:33:49 by gcros             #+#    #+#             */
/*   Updated: 2024/09/02 20:47:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_manip.h"
#include "put.h"

void	cm_put_line(t_img_p img, t_rc_event_p rc, int x)
{
	const int	o = rc->offset * rc->img->width;
	const int	p = 1;
	int			i;

	i = 0;
	while (i < img->height)
	{
		mm_img_putpixel(img, x, i, mm_img_getpixel(rc->img, o, i * p));
		i++;
	}
}
