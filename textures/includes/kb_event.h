/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:12:45 by gcros             #+#    #+#             */
/*   Updated: 2024/09/10 17:21:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KB_EVENT_H
# define KB_EVENT_H

# include "mlx_manip.h"

typedef struct s_kb_event	t_kb_event;
typedef t_kb_event			*t_kb_event_p;

struct s_kb_event
{
	char	esc;
	char	kb_key[26];
	char	kb_num[10];
	char	mouse[3];
	int		mouse_x;
	int		mouse_y;
};

void	kb_set_event(t_window_p win, t_kb_event_p kbe);
void	kb_mouse_update(t_window_p win, t_kb_event_p kbe);

#endif
