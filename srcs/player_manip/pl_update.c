/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:55:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 19:10:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "kb_event.h"

static void	update_movement(t_player_p player, t_kb_event_p kbe, t_map_p map);
static void	update_sett(t_player_p player, t_kb_event_p kbe);

void	pl_update(t_player_p player, t_kb_event_p kbe, t_map_p map)
{
	if (kb_get_event(kbe, KB_RIGHT))
		pl_turnl(player);
	if (kb_get_event(kbe, KB_LEFT))
		pl_turnr(player);
	update_movement(player, kbe, map);
	update_sett(player, kbe);
}

static void	update_movement(t_player_p player, t_kb_event_p kbe, t_map_p map)
{
	if (kb_get_event(kbe, 'w'))
		pl_walk_front(player, map);
	else if (kb_get_event(kbe, 'a'))
		pl_walk_left(player, map);
	else if (kb_get_event(kbe, 's'))
		pl_walk_back(player, map);
	else if (kb_get_event(kbe, 'd'))
		pl_walk_right(player, map);
}

static void	update_sett(t_player_p player, t_kb_event_p kbe)
{
	if (kb_get_event(kbe, 'e'))
		player->fov *= 1.01;
	else if (kb_get_event(kbe, 'q'))
		player->fov /= 1.01;
	else if (kb_get_event(kbe, 'z'))
		player->size -= 0.1;
	else if (kb_get_event(kbe, 'x'))
		player->size += 0.1;
	if (player->size > 1)
		player->size = 1;
	else if (player->size < 0.1)
		player->size = 0.1;
}
