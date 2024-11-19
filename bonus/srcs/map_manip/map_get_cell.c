/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_cell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:11:58 by gcros             #+#    #+#             */
/*   Updated: 2024/10/11 22:38:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"

t_cell_type	map_get_cell(t_map_p map, int x, int y)
{
	return (map->data[y * map->width + x]);
}

t_cell_type	map_get_cell_s(t_map_p map, int x, int y)
{
	if ((x < 0)
		+ (x >= map->width)
		+ (y < 0)
		+ (y >= map->height))
		return (ct_oob);
	return (map->data[y * map->width + x]);
}
