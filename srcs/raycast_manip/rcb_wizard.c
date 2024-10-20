/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_wizard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:01:26 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 22:25:47 by gcros            ###   ########.fr       */
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
	const double	pa = player->fov / (double)rcb->size;

	i = 0;
	a = player->angle - player->fov / 2.;
	if (a < 0)
		a += 2. * M_PI;
	while (i < rcb->size)
	{
		rcb->buf[i] = explode(map, player, a, id);
		a += pa;
		if (a >= 2. * M_PI)
			a -= 2. * M_PI;
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
	rce.img = tm_get_texture(id, id_texture_n + rc.face);
	rce.offset = rc.offset;
	return (rce);
}