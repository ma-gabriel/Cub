/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:16:24 by gcros             #+#    #+#             */
/*   Updated: 2024/11/01 13:51:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "num.h"
#include <stdio.h>
#include "put.h"

int			is_compatible(t_cell_type ct1, t_cell_type ct2);
static int	on_error(int i, int j, char c);

int	map_isvalide(t_map_p map)
{
	int			i;
	int			j;
	t_cell_type	c;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			c = map_get_cell(map, i, j);
			if (!is_compatible(c, map_get_cell_s(map, i + 1, j)))
				return (on_error(i, j, map_get_cell_s(map, i + 1, j)));
			if (!is_compatible(c, map_get_cell_s(map, i, j + 1)))
				return (on_error(i, j, map_get_cell_s(map, i, j + 1)));
			if (!is_compatible(c, map_get_cell_s(map, i - 1, j)))
				return (on_error(i, j, map_get_cell_s(map, i - 1, j)));
			if (!is_compatible(c, map_get_cell_s(map, i, j - 1)))
				return (on_error(i, j, map_get_cell_s(map, i, j - 1)));
			i++;
		}
		j++;
	}
	return (1);
}

static int	on_error(int i, int j, char c)
{
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd("parsing: bad character at [", 2);
	ft_putnbr_fd(i, 2);
	ft_putstr_fd(", ", 2);
	ft_putnbr_fd(j, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd(": type found `", 2);
	ft_putnbr_fd(c, 2);
	ft_putstr_fd("`", 2);
	ft_putendl_fd("", 2);
	return (0);
}

int	is_compatible(t_cell_type ct1, t_cell_type ct2)
{
	static int	tmp[CT_LENGHT][CT_LENGHT] = {
	[ct_unknow] = {[ct_unknow] = 1},
	[ct_void] = {[ct_unknow] = 1, [ct_void] = 1},
	[ct_wall] = {[ct_unknow] = 1, [ct_void] = 1, [ct_wall] = 1},
	[ct_door_open] = {[ct_unknow] = 0, [ct_void] = 0, [ct_wall] = 1,
	[ct_door_open] = 1},
	[ct_door_close] = {[ct_unknow] = 0, [ct_void] = 0, [ct_wall] = 1,
	[ct_door_open] = 1, [ct_door_close] = 1},
	[ct_floor] = {[ct_unknow] = 0, [ct_void] = 0, [ct_wall] = 1,
	[ct_door_close] = 1, [ct_door_open] = 1, [ct_floor] = 1},
	[ct_oob] = {[ct_unknow] = 1, [ct_void] = 1, [ct_wall] = 1,
	[ct_door_close] = 0, [ct_door_open] = 0, [ct_floor] = 0, [ct_oob] = 1},
	[ct_bwall_start] = {[ct_wall] = 1, [ct_door_close] = 1, [ct_door_open] = 1,
	[ct_bwall_start] = 1, [ct_floor] = 1},
	};

	return (tmp[ft_max(ct1, ct2)][ft_min(ct1, ct2)]);
}
