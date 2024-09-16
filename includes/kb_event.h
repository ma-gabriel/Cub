/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:12:45 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 16:57:06 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KB_EVENT_H
# define KB_EVENT_H

# include "typedef.h"

# define KB_LEFT 65361
# define KB_UP 65362
# define KB_RIGHT 65363
# define KB_DOWN 65364
# define KB_ESC 0xFF1b

struct s_kb_event
{
	char	esc;
	char	kb_key[26];
	char	kb_num[10];
	char	arrow[4];
	char	mouse[3];
	int		mouse_x;
	int		mouse_y;
};

void	kb_set_event(t_window_p win, t_kb_event_p kbe);
void	kb_mouse_update(t_window_p win, t_kb_event_p kbe);
char	kb_get_event(t_kb_event_p kbe, int kc);

#endif
