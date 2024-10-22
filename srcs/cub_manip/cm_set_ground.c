/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_set_ground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:39:49 by gcros             #+#    #+#             */
/*   Updated: 2024/09/02 16:48:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	cm_set_ground(t_img_p img, const t_color color)
{
	const int	end = img->width * img->height;
	int			i;

	i = (end) >> 1;
	while (i < end)
		img->addr[i++] = color;
}
