/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:23:12 by gcros             #+#    #+#             */
/*   Updated: 2024/10/22 18:56:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "cub.h"
#include "kb_event.h"
#include "raycast_manip.h"
#include <math.h>
#include <stdio.h>

void	update_door(t_map_p map, t_cub_p cub);

void	map_update(t_map_p map, t_kb_event_p kbe, t_cub_p cub)
{
	static int	last;

	if (kb_get_event(kbe, KB_SPACE))
	{
		if (last == 0)
			update_door(map, cub);
		last = 1;
	}
	else
		last = 0;
}

void	update_door(t_map_p map, t_cub_p cub)
{
	t_cell_flags	cf;
	t_raycast		rc;

	rc = rc_throw(map, cub->player.pos, cub->player.angle,
		(t_cell_flag){cf_canclose | cf_canopen | cf_cast});
	if (rc.dist > 1.)
		return ;
	cf = map_cell_setting(map_get_cell(map, floor(rc.pos.x), floor(rc.pos.y)),
			cf_canclose | cf_canopen);
	if (cf & cf_canclose)
		map->data[(int)floor(rc.pos.y) * map->width + (int)floor(rc.pos.x)]++;
	else if (cf & cf_canopen)
		map->data[(int)floor(rc.pos.y) * map->width + (int)floor(rc.pos.x)]--;
}
