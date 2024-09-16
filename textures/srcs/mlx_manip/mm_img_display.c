/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_img_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:50:33 by gcros             #+#    #+#             */
/*   Updated: 2024/08/22 13:32:18 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"

inline void	mm_img_display(t_img_p img, t_window_p win, int x, int y)
{
	mlx_put_image_to_window(
		win->mlx_ptr,
		win->win_ptr,
		img->img_ptr,
		x,
		y);
}
