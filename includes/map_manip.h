/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:01 by gcros             #+#    #+#             */
/*   Updated: 2024/09/13 16:48:34 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MANIP_H
# define MAP_MANIP_H

# include "draw.h"

typedef enum e_cell_type	t_cell_type;
typedef enum e_cell_flags	t_cell_flags;
typedef struct s_cell_flag	t_cell_flag;
typedef struct s_map		t_map;
typedef struct s_map		*t_map_p;

enum e_cell_type
{
	ct_unknow,
	ct_void,
	ct_wall,
	ct_door_close,
	ct_door_open,
	ct_floor,
	ct_terminated,
};
# define CT_LENGHT ct_terminated

enum e_cell_flags
{
	cf_collide = 0x1 << 0,
	cf_canopen = 0x1 << 1,
	cf_isopen = 0x1 << 2,
	cf_canclose = 0x1 << 3,
};

struct s_map
{
	t_cell_type		*data;
	t_vec2			start_pos;
	double			start_orient;
	int				height;
	int				width;
};

struct s_cell_flag
{
	int	flags:sizeof(t_cell_flags) + 1;
};

int			map_isvalide(t_map_p map);
int			map_parse(t_map_p map, char **raw_map);
void		map_fill(t_map_p map, t_img_p img);
t_image_p	map_to_image(t_mlx_p mlx, t_map_p map, int width, int height);
t_cell_type	map_cell_get_type(char c);

#endif
