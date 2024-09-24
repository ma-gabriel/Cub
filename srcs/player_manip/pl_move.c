/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:15:48 by gcros             #+#    #+#             */
/*   Updated: 2024/09/24 21:56:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_PI_2 0

#include "player_manip.h"
#include "math.h"

void	move_to(t_player_p player, t_vec2 next_pos, t_map_p map);

void	pl_walk_front(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){cos(player->angle) * PLAYER_MOVE + player->pos.x,
		sin(player->angle) * PLAYER_MOVE + player->pos.y};
	move_to(player, next_pos, map);
}

void	pl_walk_back(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){cos(player->angle) * -PLAYER_MOVE + player->pos.x,
		sin(player->angle) * -PLAYER_MOVE + player->pos.y};
	move_to(player, next_pos, map);
}

void	pl_walk_left(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){cos(player->angle + M_PI_2) * -PLAYER_MOVE + player->pos.x,
		sin(player->angle + M_PI_2) * -PLAYER_MOVE + player->pos.y};
	move_to(player, next_pos, map);
}

void	pl_walk_right(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){cos(player->angle - M_PI_2) * -PLAYER_MOVE + player->pos.x,
		sin(player->angle - M_PI_2) * -PLAYER_MOVE + player->pos.y};
	move_to(player, next_pos, map);
}

void	move_to(t_player_p player, t_vec2 next_pos, t_map_p map)
{
	player->pos = next_pos;
	(void) map;
	// todo: check collision
}
