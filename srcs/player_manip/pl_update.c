/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:55:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/19 23:42:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "kb_event.h"

void	pl_update(t_player_p player, t_kb_event_p kbe, t_map_p map)
{
	if (kb_get_event(kbe, KB_RIGHT))
		pl_turnl(player);
	if (kb_get_event(kbe, KB_LEFT))
		pl_turnr(player);
	if (kb_get_event(kbe, 'w'))
		pl_walk_front(player, map);
	if (kb_get_event(kbe, 'a'))
		pl_walk_left(player, map);
	if (kb_get_event(kbe, 's'))
		pl_walk_back(player, map);
	if (kb_get_event(kbe, 'd'))
		pl_walk_right(player, map);
	if (kb_get_event(kbe, 'e'))
		player->fov *= 1.01;
	if (kb_get_event(kbe, 'q'))
		player->fov /= 1.01;
}
