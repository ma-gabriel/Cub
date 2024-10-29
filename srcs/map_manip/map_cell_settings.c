/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cell_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:27:16 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 13:13:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"

int	map_cell_setting(t_cell_type type, size_t mask)
{
	static t_cell_flag	tmp[CT_LENGHT] = {
	[ct_void] = {0},
	[ct_wall] = {cf_collide | cf_cast},
	[ct_door_close] = {cf_collide | cf_canopen | cf_cast},
	[ct_door_open] = {cf_canclose},
	[ct_floor] = {0},
	[ct_unknow] = {0},
	[ct_oob] = {cf_oob | cf_collide | cf_cast},
	[ct_bwall_start] = {cf_collide | cf_cast | cf_breakable},
	[ct_bwall_end] = {cf_collide | cf_cast | cf_breaking},
	};

	if (type > ct_bwall_start && type <= ct_bwall_end)
		type = ct_bwall_end;
	if (type > CT_LENGHT || type < 0)
		type = ct_unknow;
	return (tmp[type].flags & mask);
}
