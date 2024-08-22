/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_getpixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:21:00 by gcros             #+#    #+#             */
/*   Updated: 2024/08/22 13:21:49 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

inline t_color	mm_img_getpixel(register t_img_p img,
	register int x,
	register int y)
{
	return (img->addr[y * (img->size_line >> 2) + x]);
}
