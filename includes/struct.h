/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:24 by geymat            #+#    #+#             */
/*   Updated: 2024/10/15 18:05:28 by gcros            ###   ########.fr       */
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
	t_img		images[4 + 2 + SPRITE_IMGS];
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_color		f;
	t_color		c;
	t_sprite	sprite;
}		t_textures;

typedef struct s_game
{
	t_textures	textures;
	char		**map;
	t_window	window;
}	t_thegame;

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

int			loop(t_loop_param *param);

#endif
