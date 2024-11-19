/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:01 by gcros             #+#    #+#             */
/*   Updated: 2024/11/19 16:18:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MANIP_H
# define MAP_MANIP_H

# include "typedef.h"
# include "struct.h"
# include "draw.h"
# include "defines.h"

typedef enum e_cell_type		t_cell_type;
typedef enum e_cell_attribute	t_cell_flags;

enum e_cell_type
{
	ct_unknow,
	ct_void,
	ct_wall,
	ct_floor,
	ct_oob,
	ct_terminated,
};

# define CT_LENGHT ct_terminated

enum e_cell_attribute
{
	cf_none = 0,
	cf_collide = 0x1 << 0,
	cf_oob = 0x1 << 4,
	cf_cast = 0x1 << 5,
};

struct s_map
{
	t_cell_type		*data;
	t_vec2			start_pos;
	double			start_orient;
	int				height;
	int				width;
};

struct s_minimap
{
	int		width;
	int		height;
	t_img_p	img;
};

struct s_cell_attr
{
	size_t	value;
};

# define UPDATE_MAP_DELAY 25

int			map_isvalide(t_map_p map);
int			map_parse(t_map_p map, char **raw_map);
t_cell_type	map_cell_get_type(char c);
t_cell_type	map_get_cell(t_map_p map, int x, int y);
t_cell_type	map_get_cell_s(t_map_p map, int x, int y);
int			map_cell_setting(t_cell_type type, size_t mask);
t_color		cell_get_color(t_cell_type type);

#endif
