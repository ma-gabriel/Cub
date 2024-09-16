/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:19:59 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 17:13:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include <stdlib.h>
#include "str.h"
#include "num.h"
#include "mem.h"
#include <math.h>

static size_t	get_map_size(char **raw_map, int *width, int *height);
static int		from_raw(t_map_p map, char **raw_map);
static int	get_start(t_map_p map, char **raw_map);

int	map_parse(t_map_p map, char **raw_map)
{
	map->data = (t_cell_type *)malloc(sizeof(t_cell_type)
			* get_map_size(raw_map, &map->width, &map->height) + 1);
	if (map->data == NULL)
		return (0);
	if (from_raw(map, raw_map) || get_start(map, raw_map))
	{
		free(map->data);
		return (0);
	}
	return (1);
}

static int	get_start(t_map_p map, char **raw_map)
{
	char	c;
	int		i;
	int		j;

	j = 0;
	while (raw_map[j])
	{
		i = 0;
		while (raw_map[j][i])
		{
			c = raw_map[j][i];
			if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
			{
				map->start_pos = (t_vec2){.x = i, .y = j};
				map->start_orient = 0;											//todo
			}
			i++;
		}
		j++;
	}
	return (0);
}

static int	from_raw(t_map_p map, char **raw_map)
{
	int	i;
	int	j;

	i = 0;
	while (raw_map[i])
	{
		j = 0;
		while (raw_map[i][j])
		{
			map->data[i * map->width + j] = map_cell_get_type(raw_map[i][j]);
			j++;
		}
		while (j < map->width)
		{
			map->data[i * map->width + j] = ct_unknow;
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	get_map_size(char **raw_map, int *width, int *height)
{
	*height = 0;
	*width = 0;
	while (raw_map[*height])
	{
		*width = ft_max(ft_strlen(raw_map[*height]), *width);
		(*height)++;
	}
	return ((*height) * (*width));
}
