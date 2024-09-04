/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_mouse_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:39:03 by gcros             #+#    #+#             */
/*   Updated: 2024/09/04 21:46:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "kb_event.h"

void	kb_mouse_update(t_window_p win, t_kb_event_p kbe)
{
	mlx_mouse_get_pos(win->mlx_ptr, win->win_ptr, &kbe->mouse_x, &kbe->mouse_y);
}
