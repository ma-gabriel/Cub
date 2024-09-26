/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:16:24 by gcros             #+#    #+#             */
/*   Updated: 2024/09/13 16:23:52 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "num.h"

int	map_isvalide(t_map_p map)
{
	(void) map;
	return (1);
}

int	is_compatible(t_cell_type ct1, t_cell_type ct2)
{
	static int	tmp[CT_LENGHT][CT_LENGHT] = {
	[ct_unknow] = {[ct_unknow] = 1},
	[ct_void] = {[ct_unknow] = 1, [ct_void] = 1},
	[ct_wall] = {[ct_unknow] = 1, [ct_void] = 1, [ct_wall] = 1},
	[ct_door_close] = {[ct_unknow] = 0, [ct_void] = 0, [ct_wall] = 1,
	[ct_door_close] = 1},
	[ct_door_open] = {[ct_unknow] = 0, [ct_void] = 0, [ct_wall] = 1,
	[ct_door_close] = 1, [ct_door_open] = 0},
	[ct_floor] = {[ct_unknow] = 0, [ct_void] = 0, [ct_wall] = 1,
	[ct_door_close] = 1, [ct_door_open] = 1, [ct_floor] = 1},
	};

	return (tmp[ft_min(ct1, ct2)][ft_max(ct1, ct2)]);
}