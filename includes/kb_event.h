/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:12:45 by gcros             #+#    #+#             */
/*   Updated: 2024/10/30 14:30:31 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KB_EVENT_H
# define KB_EVENT_H

# include "typedef.h"
#include <X11/keysym.h>

# define KB_LEFT 65361
# define KB_UP 65362
# define KB_RIGHT 65363
# define KB_DOWN 65364
# define KB_ESC 0xFF1b
# define KB_TAB 65289
# define KB_SPACE ' '
# define KB_RCTRL 0xffe3
# define KB_LCTRL 0xffe4
# define MOUSE1 -1
# define MOUSE2 -2
# define MOUSE3 -3

# define MOUSE_TRIG KB_RCTRL

struct s_kb_event
{
	char	esc;
	char	kb_key[26];
	char	kb_num[10];
	char	arrow[4];
	char	mouse[3];
	int		mouse_x;
	int		mouse_y;
	int		lmouse_x;
	int		lmouse_y;
	int		tab;
	int		space;
	int		ctrl;
};

void	kb_set_event(t_window_p win, t_kb_event_p kbe);
void	kb_mouse_update(t_window_p win, t_kb_event_p kbe);
char	kb_get_event(t_kb_event_p kbe, int kc);

#endif
