/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_set_bg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:17:43 by gcros             #+#    #+#             */
/*   Updated: 2024/10/16 23:58:31 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

void	mm_img_set_bg(t_img_p img, const t_color color)
{
	// int		i;
	t_color			*c;
	const t_color	*end = img->addr + img->height * img->width; 

	c = img->addr;
	// i = img->height * img->width;
	while (c != end)
	{
		*c = color;
		c++;
	}
}
