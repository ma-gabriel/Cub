/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_set_sky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:39:49 by gcros             #+#    #+#             */
/*   Updated: 2024/11/05 14:26:03 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	cm_set_sky(restrict t_img_p img, register t_color color)
{
	const int	end = (img->width * img->height) >> 1;
	int			i;

	i = 0;
	while (i < end)
		img->addr[i++] = color;
}
