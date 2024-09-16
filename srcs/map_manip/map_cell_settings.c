/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cell_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:27:16 by gcros             #+#    #+#             */
/*   Updated: 2024/09/13 16:43:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"

t_cell_flag	map_cell_setting(t_cell_type type, int mask)
{
	static t_cell_flag	tmp[CT_LENGHT] = {
	[ct_void] = {0},
	[ct_wall] = {cf_collide},
	[ct_door_close] = {cf_collide | cf_canopen},
	[ct_door_open] = {cf_isopen | cf_canclose},
	[ct_floor] = {0},
	[ct_unknow] = {0},
	};

	if (type > CT_LENGHT)
		return ((t_cell_flag){0});
	return ((t_cell_flag){tmp[type].flags & mask});
}

