/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:45:17 by gcros             #+#    #+#             */
/*   Updated: 2024/09/24 15:52:07 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"

void	pl_turnl(t_player_p player)
{
	player->angle += PLAYER_TURN;
}

void	pl_turnr(t_player_p player)
{
	player->angle -= PLAYER_TURN;

}
