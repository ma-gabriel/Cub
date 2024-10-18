/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:45:17 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 19:33:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_PI 3.14159

#include "player_manip.h"
#include "math.h"

void	pl_turnl(t_player_p player)
{
	player->angle += PLAYER_TURN;
	while (player->angle > 2. * M_PI)
		player->angle -= 2. * M_PI;
}

void	pl_turnr(t_player_p player)
{
	player->angle -= PLAYER_TURN;
	while (player->angle < 0)
		player->angle += 2. * M_PI;
}
