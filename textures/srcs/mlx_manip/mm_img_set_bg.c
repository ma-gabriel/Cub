/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_set_bg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:17:43 by gcros             #+#    #+#             */
/*   Updated: 2024/08/21 13:50:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	mm_img_set_bg(t_img_p img, const t_color color)
{
	int	i;

	i = img->height * img->width;
	while (i-- > 0)
		img->addr[i] = color;
}
