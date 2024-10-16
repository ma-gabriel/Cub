/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:24 by geymat            #+#    #+#             */
/*   Updated: 2024/10/17 01:36:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "typedef.h"
# include "mlx_manip.h"
# include "defines.h"
# include <stdlib.h>

typedef struct s_sprite
{
	t_img		images[SPRITE_IMGS];
	size_t		index;
}		t_sprite;

typedef struct s_textures
{
	t_img_p		images[4 + 2 + SPRITE_IMGS];
	t_img_p		no;
	t_img_p		so;
	t_img_p		we;
	t_img_p		ea;
	t_color		f;
	t_color		c;
	t_sprite	sprite;
}		t_textures;

typedef struct s_parse
{
	t_textures	textures;
	char		**map;
	t_window	window;
}	t_parse;

struct s_vec2
{
	double	x;
	double	y;
};

struct s_loop_param
{
	t_mlx_p				mlx;
	t_window_p			win;
	t_kb_event_p		kbe;
	t_player_p			player;
	t_map_p				map;
	t_minimap_p			minimap;
	t_img_descriptor_p	id;
};

int	loop(t_cub_p cub);

#endif
