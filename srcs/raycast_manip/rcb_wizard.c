/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_wizard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:01:26 by gcros             #+#    #+#             */
/*   Updated: 2024/10/21 17:54:11 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "player_manip.h"
#include "raycast_manip.h"
#include <stdio.h>
#include <math.h>
#include "texture_manip.h"

static t_rc_event	explode(t_map_p map,
						t_player_p player, double angle, t_img_descriptor_p id);

void	rcb_wizard(t_rc_buf_p rcb, t_map_p map,
			t_player_p player, t_img_descriptor_p id)
{
	size_t			i;
	double			a;
	const double	r = (1. / (double) WIN_WIDTH * THICKNESS_RAYS) * player->fov;

	i = 0;
	while (i < rcb->size)
	{
		a = atan(((double)((ssize_t)(i - (rcb->size >> 1)))) * r) + player->angle;
		rcb->buf[i] = explode(map, player, a, id);
		i++;
	}
}

static t_rc_event	explode(t_map_p map,
	t_player_p player, double angle, t_img_descriptor_p id)
{
	t_raycast	rc;
	t_rc_event	rce;

	rc = rc_throw(map, player->pos, angle, (t_cell_flag){cf_cast});
	rce.collision = rc.pos;
	rce.start = player->pos;
	rce.dist = rc.dist * cos(player->angle - angle);
	rce.offset = rc.offset;
	rce.img = tm_get_texture(id, id_texture_e + rc.face);
	// rce.img = tm_get_texture(id, 0 + rc.face);
	// rce.img = tm_get_texture(id, id_minimap);
	return (rce);
}
