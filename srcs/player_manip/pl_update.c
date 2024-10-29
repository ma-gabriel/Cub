/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:55:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 22:47:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "kb_event.h"

static void	update_movement(t_player_p player, t_kb_event_p kbe, t_map_p map);
static void	update_sett(t_player_p player, t_kb_event_p kbe);
static void	update_orientation(t_player_p player, t_kb_event_p kbe);

void	pl_update(t_player_p player, t_kb_event_p kbe, t_map_p map)
{
	update_orientation(player, kbe);
	update_movement(player, kbe, map);
	update_sett(player, kbe);
}

static void	update_orientation(t_player_p player, t_kb_event_p kbe)
{
	if (kb_get_event(kbe, KB_RIGHT))
		pl_turnl(player);
	if (kb_get_event(kbe, KB_LEFT))
		pl_turnr(player);
	if (kbe->mouse[0])
	{
		player->angle += ((kbe->mouse_x - kbe->lmouse_x) * 0.0015);
	}
}

static void	update_movement(t_player_p player, t_kb_event_p kbe, t_map_p map)
{
	if (kb_get_event(kbe, 'w'))
		pl_walk_front(player, map);
	if (kb_get_event(kbe, 'a'))
		pl_walk_left(player, map);
	if (kb_get_event(kbe, 's'))
		pl_walk_back(player, map);
	if (kb_get_event(kbe, 'd'))
		pl_walk_right(player, map);
}

static void	update_sett(t_player_p player, t_kb_event_p kbe)
{
	if (kb_get_event(kbe, 'e'))
		player->fov *= 1.01;
	if (kb_get_event(kbe, 'q'))
		player->fov /= 1.01;
	if (kb_get_event(kbe, 'z'))
		player->size -= 0.1;
	if (kb_get_event(kbe, 'x'))
		player->size += 0.1;
	if (player->size > .9)
		player->size = .9;
	if (player->size < .1)
		player->size = .1;
}
