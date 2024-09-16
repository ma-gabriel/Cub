/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:55:28 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 16:53:30 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "kb_event.h"

void	pl_update(t_player_p player, t_kb_event_p kbe)
{
	if (kb_get_event(kbe, 'e'))
		player->angle += PLAYER_TURN;
	if (kb_get_event(kbe, 'q'))
		player->angle -= PLAYER_TURN;
}
