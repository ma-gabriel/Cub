/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:05:39 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 15:13:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include <stdio.h>

void	pl_print(t_player_p player)
{
	printf("player: {.x = %lf, .y = %lf, .angle = %lf}\n",
		player->pos.x, player->pos.y, player->angle);
}
