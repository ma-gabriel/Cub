/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:01 by gcros             #+#    #+#             */
/*   Updated: 2024/10/28 15:59:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MANIP_H
# define MAP_MANIP_H

# include "typedef.h"
# include "struct.h"
# include "draw.h"
# include "defines.h"

typedef enum e_cell_type	t_cell_type;
typedef enum e_cell_flags	t_cell_flags;

enum e_cell_type
{
	ct_unknow,
	ct_void,
	ct_wall,
	ct_door_open,
	ct_door_close,
	ct_floor,
	ct_oob,
	ct_bwall_start,
	ct_bwall_end = ct_bwall_start + SPRITE_IMGS,
	ct_terminated,
};

# define CT_LENGHT ct_terminated

enum e_cell_flags
{
	cf_none = 0,
	cf_collide = 0x1 << 0,
	cf_canopen = 0x1 << 1,
	cf_isopen = 0x1 << 2,
	cf_canclose = 0x1 << 3,
	cf_oob = 0x1 << 4,
	cf_cast = 0x1 << 5,
	cf_breakable = 0x1 << 6,
	cf_breaking = 0x1 << 7,
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


struct s_cell_flag
{
	int	flags;
};

# define UPDATE_MAP_DELAY 100

int			map_isvalide(t_map_p map);
int			map_parse(t_map_p map, char **raw_map);
void		map_draw(t_map_p map, t_img_p img);
t_cell_type	map_cell_get_type(char c);
t_cell_type	map_get_cell(t_map_p map, int x, int y);
t_cell_type	map_get_cell_s(t_map_p map, int x, int y);
int			map_cell_setting(t_cell_type type, int mask);
t_color		cell_get_color(t_cell_type type);

void		minimap_draw(t_minimap_p minimap, t_map_p map,
				t_player_p player, t_rc_buf_p rcb);
int			minimap_init(t_minimap_p minimap, t_img_p img,
				int width, int height);
void		minimap_update(t_minimap_p minimap, t_kb_event_p kbe);
void		map_update(t_map_p map, t_kb_event_p kbe, t_cub_p cub);

#endif
