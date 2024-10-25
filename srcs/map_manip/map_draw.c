/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:11:30 by gcros             #+#    #+#             */
/*   Updated: 2024/10/25 16:47:57 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "draw.h"
#include "str.h"
#include "put.h"
#include "map_manip.h"

size_t	strs_len(char **strs);

t_color	cell_get_color(t_cell_type type)
{
	static t_color	tmp[CT_LENGHT] = {
	[ct_void] = {.value = 0xFF646464},
	[ct_wall] = {.value = 0x7F000000},
	[ct_door_close] = {.value = 0x7FC86464},
	[ct_door_open] = {.value = 0x7FC8C8C8},
	[ct_floor] = {.value = ~0xFF000000},
	[ct_unknow] = {.value = 0xFF646464},
	[ct_oob] = {.value = 0xFF0000FF},
	[ct_bwall_start] = {.value = 0x7F000000},
	};

	if (type >= ct_bwall_start && type <= ct_bwall_end)
		type = ct_wall;
	else if (type > CT_LENGHT)
		type = ct_unknow;
	return (tmp[type]);
}

void	map_draw(t_map_p map, t_img_p img)
{
	int				i;
	int				j;
	t_color			c;
	const t_vec2	ratio = (t_vec2){img->width / (double)map->width,
		img->height / (double)map->height};

	i = map->height;
	while (i--)
	{
		j = map->width;
		while (j--)
		{
			c = cell_get_color(map->data[i * map->width + j]);
			draw_rect(img, (t_vec2){(j * ratio.x),
				(i * ratio.y)},
				(t_vec2){ratio.x + 1., ratio.y + 1.}, c);
		}
	}
}
