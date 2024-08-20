/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_set_bg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:17:43 by gcros             #+#    #+#             */
/*   Updated: 2024/08/20 19:29:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	mm_img_set_bg(t_img_p img, t_color color)
{
	int	i;

	i = 0;
	while (i < img->height * img->width)
	{
		img->addr[i] = color;
		i++;
	}
}
