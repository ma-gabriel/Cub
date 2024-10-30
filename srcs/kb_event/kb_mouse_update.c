/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_mouse_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:39:03 by gcros             #+#    #+#             */
/*   Updated: 2024/10/30 14:20:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "kb_event.h"
#include "mlx_manip.h"

static void	update_posy(t_window_p win, t_kb_event_p kbe, int height);
static void	update_posx(t_window_p win, t_kb_event_p kbe, int width);

void	kb_mouse_update(t_window_p win, t_kb_event_p kbe)
{
	int	width;
	int	height;

	mlx_get_screen_size(win->mlx_ptr, &width, &height);
	kbe->lmouse_x = kbe->mouse_x;
	kbe->lmouse_y = kbe->mouse_y;
	mlx_mouse_get_pos(win->mlx_ptr, win->win_ptr, &kbe->mouse_x, &kbe->mouse_y);
	if (!kb_get_event(kbe, MOUSE_TRIG))
		return ;
	update_posx(win, kbe, width);
	update_posy(win, kbe, height);
	mlx_mouse_get_pos(win->mlx_ptr, win->win_ptr, &kbe->mouse_x, &kbe->mouse_y);
}

static void	update_posx(t_window_p win, t_kb_event_p kbe, int width)
{
	if (kbe->mouse_x > width * .9)
	{
		kbe->mouse_x = width * .1;
		kbe->lmouse_x -= .8 * width;
		mlx_mouse_move(win->mlx_ptr, win->win_ptr, kbe->mouse_x, kbe->mouse_y);
	}
	else if (kbe->mouse_x < width * .1)
	{
		kbe->mouse_x = width * .9;
		kbe->lmouse_x += .8 * width;
		mlx_mouse_move(win->mlx_ptr, win->win_ptr, kbe->mouse_x, kbe->mouse_y);
	}
}

static void	update_posy(t_window_p win, t_kb_event_p kbe, int height)
{
	if (kbe->mouse_y > height * .9)
	{
		kbe->mouse_y = height * .1;
		kbe->lmouse_y -= .8 * height;
		mlx_mouse_move(win->mlx_ptr, win->win_ptr, kbe->mouse_x, kbe->mouse_y);
	}
	else if (kbe->mouse_y < height * .1)
	{
		kbe->mouse_y = height * .9;
		kbe->lmouse_y += .8 * height;
		mlx_mouse_move(win->mlx_ptr, win->win_ptr, kbe->mouse_x, kbe->mouse_y);
	}
}
