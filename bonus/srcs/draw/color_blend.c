/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:12:12 by gcros             #+#    #+#             */
/*   Updated: 2024/11/13 18:13:46 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx_manip.h"

t_color	color_blend(const t_color c1, const t_color c2)
{
	t_color	o;
	double	a1;

	if (c1.a == 0)
		return (c1);
	else if (c1.a == 255)
	{
		o = c2;
		o.a = 255;
		return (o);
	}
	a1 = c1.a * 0.00392156863;
	o.r = c1.r * (1. - a1) + c2.r * a1;
	o.g = c1.g * (1. - a1) + c2.g * a1;
	o.b = c1.b * (1. - a1) + c2.b * a1;
	o.a = 255;
	return (o);
}
