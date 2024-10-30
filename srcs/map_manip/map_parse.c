/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:19:59 by gcros             #+#    #+#             */
/*   Updated: 2024/10/30 17:02:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_PI 3.14159
#include "map_manip.h"
#include <stdlib.h>
#include "str.h"
#include "num.h"
#include "mem.h"
#include <math.h>
#include <stdio.h>
#include "put.h"

static size_t	get_map_size(char **raw_map, int *width, int *height);
static int		from_raw(t_map_p map, char **raw_map);
static int		get_start(t_map_p map, char **raw_map);
static double	get_orient(char c);

int	map_parse(t_map_p map, char **raw_map)
{
	map->data = (t_cell_type *)malloc(sizeof(t_cell_type)
			* get_map_size(raw_map, &map->width, &map->height) + 1);
	if (map->data == NULL)
		return (1);
	if (from_raw(map, raw_map) || get_start(map, raw_map) || !map_isvalide(map))
	{
		ft_putendl_fd(ERR"parsing: ???, "
			"or invalide char", 2);
		free(map->data);
		map->data = NULL;
		return (1);
	}
	return (0);
}

static int	get_start(t_map_p map, char **raw_map)
{
	char	c;
	int		i;
	int		j;
	int		v;

	j = -1;
	v = 0;
	while (raw_map[++j])
	{
		i = -1;
		while (raw_map[j][++i])
		{
			c = raw_map[j][i];
			if ((c == 'N' || c == 'W' || c == 'S' || c == 'E') && ++v)
			{
				map->start_pos = (t_vec2){.x = i + 0.5, .y = j + 0.5};
				map->start_orient = get_orient(c);
			}
		}
	}
	if (v == 0)
		ft_putstr_fd(ERR NO_START NL, 2);
	else if (v > 1)
		ft_putstr_fd(ERR MULTIPLE_START NL, 2);
	return (v != 1);
}

static double	get_orient(char c)
{
	if (c == 'N')
		return (3 * M_PI / 2);
	if (c == 'W')
		return (0);
	if (c == 'S')
		return (M_PI / 2);
	if (c == 'E')
		return (M_PI);
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
