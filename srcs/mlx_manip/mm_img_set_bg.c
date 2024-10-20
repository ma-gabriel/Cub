/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_set_bg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:17:43 by gcros             #+#    #+#             */
/*   Updated: 2024/10/20 17:59:45 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	mm_img_set_bg(t_img_p img, const t_color color)
{
	t_color			*c;
	const t_color	*end = img->addr + img->height * img->width;

	c = img->addr;
	while (c != end)
	{
		*c = color;
		c++;
	}
}
