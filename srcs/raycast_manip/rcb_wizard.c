/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_wizard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:01:26 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 18:02:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "player_manip.h"
#include "raycast_manip.h"
#include <stdio.h>

void	rcb_wizard(t_rc_buf_p rcb, t_map_p map,
			t_player_p player, t_img_descriptor_p id)
{
	size_t		i;
	t_raycast	r;

	(void)rcb, (void)map, (void)player, (void)id;
	i = 0;
	while (i < rcb->size)
	{
		r = (t_raycast){.angle = player->angle, .start = player->pos, .flags = 0};
		rcb->buf[i] = rc_throw(map, r, id);
		i++;
	}
}
