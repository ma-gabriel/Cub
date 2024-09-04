/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:12:45 by gcros             #+#    #+#             */
/*   Updated: 2024/09/04 22:08:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KB_EVENT_H
# define KB_EVENT_H

# include "typedef.h"
# include "mlx_manip.h"

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
