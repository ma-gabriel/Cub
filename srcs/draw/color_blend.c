/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:12:12 by gcros             #+#    #+#             */
/*   Updated: 2024/11/05 15:34:59 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx_manip.h"

t_color	color_blend(const t_color c1, const t_color c2)
{
	const double	a1 = 1. - ((double)c1.a / 255.);
	const double	a2 = 1;
	const double	ao = a1 + a2 * (1. - a1);
	const double	rev = 1. / ao;
	t_color			o;

	o.r = (((double)c1.r * a1 + ((double)c2.r * a2) * (1. - a1)) * rev);
	o.g = (((double)c1.g * a1 + ((double)c2.g * a2) * (1. - a1)) * rev);
	o.b = (((double)c1.b * a1 + ((double)c2.b * a2) * (1. - a1)) * rev);
	o.a = (1. - a2) * 255.;
	return (o);
}

// t_color	color_blend(t_color c1, t_color c2)
// {
// 	t_color			o;
// 	const double	a2 = (double)c2.a / 255.;

// 	o = (t_color){
// 		.r = c1.r * (1 - a2) + c2.r * a2,
// 		.g = c1.g * (1 - a2) + c2.g * a2,
// 		.b = c1.b * (1 - a2) + c2.b * a2,
// 		.a = 0,
// 	};
// 	return (o);
// }
