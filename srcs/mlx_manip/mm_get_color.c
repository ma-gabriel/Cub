/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:13:31 by gcros             #+#    #+#             */
/*   Updated: 2024/08/21 17:54:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

/*
	return ((t_color){.value = ((unsigned char)a << 24
			| (unsigned char)r << 16 | (unsigned char)g << 8
			| (unsigned char)b)});
*/
inline t_color	mm_get_color(register int a,
	register int r,
	register int g,
	register int b)
{
	return ((t_color){.a = a, .r = r, .g = g, .b = b});
}
