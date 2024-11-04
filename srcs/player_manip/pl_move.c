/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:15:48 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 16:13:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "map_manip.h"
#include <math.h>
#include <stdio.h>
#include "put.h"
#include "libft.h"

void	pl_walk_front(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){
		cos(player->angle) * PLAYER_MOVE + player->pos.x,
		sin(player->angle) * PLAYER_MOVE + player->pos.y};
	pl_collide(player, map, next_pos, ft_norm_angle(player->angle));
}

void	pl_walk_back(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){
		cos(player->angle + M_PI) * PLAYER_MOVE + player->pos.x,
		sin(player->angle + M_PI) * PLAYER_MOVE + player->pos.y};
	pl_collide(player, map, next_pos, ft_norm_angle(player->angle + M_PI));
}

void	pl_walk_left(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){
		cos(player->angle - M_PI_2) * PLAYER_MOVE + player->pos.x,
		sin(player->angle - M_PI_2) * PLAYER_MOVE + player->pos.y};
	pl_collide(player, map, next_pos, ft_norm_angle(player->angle - M_PI_2));
}

void	pl_walk_right(t_player_p player, t_map_p map)
{
	t_vec2	next_pos;

	next_pos = (t_vec2){
		cos(player->angle + M_PI_2) * PLAYER_MOVE + player->pos.x,
		sin(player->angle + M_PI_2) * PLAYER_MOVE + player->pos.y};
	pl_collide(player, map, next_pos, ft_norm_angle(player->angle + M_PI_2));
}
