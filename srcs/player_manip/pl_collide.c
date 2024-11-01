/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_collide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:48 by gcros             #+#    #+#             */
/*   Updated: 2024/11/01 13:39:13 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "map_manip.h"
#include <math.h>
#include "libft.h"

static int	check_vertical(t_player_p player, t_map_p map,
				t_vec2 npos, double angle);
static int	check_horizontal(t_player_p player, t_map_p map,
				t_vec2 npos, double angle);

void	pl_collide(t_player_p player, t_map_p map, t_vec2 npos, double angle)
{
	check_horizontal(player, map, npos, angle);
	check_vertical(player, map, npos, angle);
}

static int	check_horizontal(t_player_p player, t_map_p map,
t_vec2 npos, double angle)
{
	const int	mod = ((angle < M_PI && angle > 0) * 2 - 1);
	t_cell_attr	attr;

	attr.value = map_cell_setting(map_get_cell_s(map,
				floor(player->pos.x + (player->size / 2.)),
				floor(npos.y + (player->size / 2.) * mod)), ~0);
	attr.value |= map_cell_setting(map_get_cell_s(map,
				floor(player->pos.x - (player->size / 2.)),
				floor(npos.y + (player->size / 2.) * mod)), ~0);
	if (attr.value & cf_oob)
		player->angle += M_PI;
	else if (attr.value &  cf_collide)
		;
	else
	{
		player->pos.y = npos.y;
		return (0);
	}
	return (1);
}

static int	check_vertical(t_player_p player, t_map_p map,
t_vec2 npos, double angle)
{
	const int	mod = -((angle > M_PI / 2.
				&& angle < 3. * M_PI / 2.) * 2 - 1);
	t_cell_attr	attr;

	attr.value = map_cell_setting(map_get_cell_s(map,
				floor(npos.x + (player->size / 2.) * mod),
				floor(player->pos.y + (player->size / 2.))), ~0);
	attr.value |= map_cell_setting(map_get_cell_s(map,
				floor(npos.x + (player->size / 2.) * mod),
				floor(player->pos.y - (player->size / 2.))), ~0);
	if (attr.value & cf_oob)
		player->angle += M_PI;
	else if (attr.value &  cf_collide)
		;
	else
	{
		player->pos.x = npos.x;
		return (0);
	}
	return (1);
}
