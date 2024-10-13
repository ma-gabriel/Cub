/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:12:12 by gcros             #+#    #+#             */
/*   Updated: 2024/10/10 19:26:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx_manip.h"

t_color color_blend(t_color c1, t_color c2)
{
	const double	a1 = 1. - ((double)c1.a / 255.);
	const double	a2 = 1. - ((double)c2.a / 255.);
	const double	ao = a1 + a2 * (1. - a1);
	t_color			o;

	o = (t_color){
		.r = (((double)c1.r * a1 + ((double)c2.r * a2) * (1. - a1)) / ao),
		.g = (((double)c1.g * a1 + ((double)c2.g * a2) * (1. - a1)) / ao),
		.b = (((double)c1.b * a1 + ((double)c2.b * a2) * (1. - a1)) / ao),
		.a = ao * 255.,
	};
	return (o);
}