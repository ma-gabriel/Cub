/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_set_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:08:31 by gcros             #+#    #+#             */
/*   Updated: 2024/10/30 14:28:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "mlx_manip.h"
#include "mlx.h"
#include "kb_event.h"
#include "mem.h"
#include "put.h"

int	key_pressed(int kc, t_kb_event_p kbe);
int	key_released(int kc, t_kb_event_p kbe);
int	mouse_pressed(int mc, int x, int y, t_kb_event_p kbe);
int	mouse_released(int mc, int x, int y, t_kb_event_p kbe);

void	kb_set_event(t_window_p win, t_kb_event_p kbe)
{
	ft_bzero(kbe, sizeof(*kbe));
	mlx_hook(win->win_ptr, 17, 1L << 1, mlx_loop_end, win->mlx_ptr);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_pressed, kbe);
	mlx_hook(win->win_ptr, 3, 1L << 1, key_released, kbe);
	mlx_hook(win->win_ptr, 4, 1L << 2, mouse_pressed, kbe);
	mlx_hook(win->win_ptr, 5, 1L << 3, mouse_released, kbe);
}

int	key_pressed(int kc, t_kb_event_p kbe)
{
	if (kc == KB_ESC)
		kbe->esc = 1;
	else if (kc == KB_TAB)
		kbe->tab = 1;
	else if (kc >= 'a' && kc <= 'z')
		kbe->kb_key[kc - 'a'] = 1;
	else if (kc >= '0' && kc <= '9')
		kbe->kb_num[kc - '0'] = 1;
	else if (kc >= KB_LEFT && kc <= KB_DOWN)
		kbe->arrow[kc - KB_LEFT] = 1;
	else if (kc == KB_SPACE)
		kbe->space = 1;
	else if (kc == KB_LCTRL || kc == KB_RCTRL)
		kbe->ctrl = 1;
	else if (kc == MOUSE1 || kc == MOUSE2 || kc == MOUSE3)
		kbe->mouse[-kc - 1] = 1;
	return (0);
}

int	key_released(int kc, t_kb_event_p kbe)
{
	if (kc == KB_ESC)
		kbe->esc = 0;
	else if (kc == KB_TAB)
		kbe->tab = 0;
	else if (kc >= 'a' && kc <= 'z')
		kbe->kb_key[kc - 'a'] = 0;
	else if (kc >= '0' && kc <= '9')
		kbe->kb_num[kc - '0'] = 0;
	else if (kc >= KB_LEFT && kc <= KB_DOWN)
		kbe->arrow[kc - KB_LEFT] = 0;
	else if (kc == KB_SPACE)
		kbe->space = 0;
	else if (kc == KB_LCTRL || kc == KB_RCTRL)
		kbe->ctrl = 0;
	else if (kc == MOUSE1 || kc == MOUSE2 || kc == MOUSE3)
		kbe->mouse[-kc - 1] = 0;
	return (0);
}

int	mouse_pressed(int mc, int x, int y, t_kb_event_p kbe)
{
	(void) (x + y);
	key_pressed(-mc, kbe);
	return (0);
}

int	mouse_released(int mc, int x, int y, t_kb_event_p kbe)
{
	(void) (x + y);
	key_released(-mc, kbe);
	return (0);
}
