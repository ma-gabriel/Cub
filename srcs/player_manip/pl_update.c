/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:55:28 by gcros             #+#    #+#             */
/*   Updated: 2024/09/24 21:35:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "kb_event.h"

void	pl_update(t_player_p player, t_kb_event_p kbe, t_map_p map)
{
	if (kb_get_event(kbe, 'e'))
		pl_turnl(player);
	if (kb_get_event(kbe, 'q'))
		pl_turnr(player);
	if (kb_get_event(kbe, 'w'))
		pl_walk_front(player, map);
	if (kb_get_event(kbe, 'a'))
		pl_walk_left(player, map);
	if (kb_get_event(kbe, 's'))
		pl_walk_back(player, map);
	if (kb_get_event(kbe, 'd'))
		pl_walk_right(player, map);
}