/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_set_sky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:39:49 by gcros             #+#    #+#             */
/*   Updated: 2024/09/02 16:48:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	cm_set_sky(t_img_p img, const t_color color)
{
	int	i;
	int	end;

	end = (img->width * img->height) >> 1;
	i = 0;
	while (i < end)
		img->addr[i++] = color;
}
