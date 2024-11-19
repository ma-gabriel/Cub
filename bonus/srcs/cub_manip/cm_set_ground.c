/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_set_ground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:39:49 by gcros             #+#    #+#             */
/*   Updated: 2024/11/05 14:26:05 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	cm_set_ground(restrict t_img_p img, register t_color color)
{
	const int	end = img->width * img->height;
	int			i;

	i = (end) >> 1;
	while (i < end)
		img->addr[i++] = color;
}
