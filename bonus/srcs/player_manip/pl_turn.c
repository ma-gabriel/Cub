/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:45:17 by gcros             #+#    #+#             */
/*   Updated: 2024/10/19 14:18:38 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_PI 3.14159

#include "player_manip.h"
#include "math.h"
#include "libft.h"

void	pl_turnl(t_player_p player)
{
	player->angle += PLAYER_TURN;
	player->angle = ft_norm_angle(player->angle);
}

void	pl_turnr(t_player_p player)
{
	player->angle -= PLAYER_TURN;
	player->angle = ft_norm_angle(player->angle);
}
