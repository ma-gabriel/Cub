/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:23:12 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 19:12:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "cub.h"
#include "kb_event.h"
#include "raycast_manip.h"
#include <math.h>
#include <stdio.h>

static void	update_door(t_map_p map, t_cub_p cub);
static void	break_wall(t_map_p map, t_cub_p cub);
static void	interact(t_map_p map, t_cub_p cub);
static void	update_map(t_map_p map);

void	map_update(t_map_p map, t_kb_event_p kbe, t_cub_p cub)
{
	static int	last;

	if (kb_get_event(kbe, KB_SPACE))
	{
		if (last == 0)
			interact(map, cub);
		last = 1;
	}
	else
		last = 0;
	if (cub->count % UPDATE_MAP_DELAY == 0)
		update_map(map);
}

static void	update_map(t_map_p map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map_get_cell(map, i, j) == ct_bwall_end)
				map->data[j * map->width + i] = ct_floor;
			if (map_cell_setting(map_get_cell(map, i, j), cf_breaking))
				map->data[j * map->width + i]++;
			i++;
		}
		j++;
	}
}

static void	interact(t_map_p map, t_cub_p cub)
{
	break_wall(map, cub);
	update_door(map, cub);
}

static void	break_wall(t_map_p map, t_cub_p cub)
{
	t_cell_flags	cf;
	t_raycast		rc;
	t_rc_sett		rcs;

	rcs = (t_rc_sett){.angle = cub->player.angle, .start = cub->player.pos,
		.flag = {cf_canclose | cf_canopen | cf_cast}, .max = 1};
	rc = rc_throw(map, rcs);
	if (rc.dist > 1.)
		return ;
	cf = map_cell_setting(map_get_cell(map, floor(rc.pos.x), floor(rc.pos.y)),
			cf_breakable);
	if (cf & cf_breakable)
		map->data[(int)floor(rc.pos.y) * map->width + (int)floor(rc.pos.x)]++;
}

static void	update_door(t_map_p map, t_cub_p cub)
{
	t_cell_flags	cf;
	t_raycast		rc;
	t_rc_sett		rcs;

	rcs = (t_rc_sett){.angle = cub->player.angle, .start = cub->player.pos,
		.flag = {cf_canclose | cf_canopen | cf_cast}, .max = 1};
	rc = rc_throw(map, rcs);
	if (rc.dist > 1. || rc.dist < (cub->player.size / 2.))
		return ;
	cf = map_cell_setting(map_get_cell(map, floor(rc.pos.x), floor(rc.pos.y)),
			cf_canclose | cf_canopen);
	if (cf & cf_canclose)
		map->data[(int)floor(rc.pos.y) * map->width + (int)floor(rc.pos.x)]++;
	else if (cf & cf_canopen)
		map->data[(int)floor(rc.pos.y) * map->width + (int)floor(rc.pos.x)]--;
}
