/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_mouse_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:39:03 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 16:24:03 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "kb_event.h"
#include "mlx_manip.h"

void	kb_mouse_update(t_window_p win, t_kb_event_p kbe)
{
	mlx_mouse_get_pos(win->mlx_ptr, win->win_ptr, &kbe->mouse_x, &kbe->mouse_y);
}
