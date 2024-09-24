/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:24 by geymat            #+#    #+#             */
/*   Updated: 2024/09/24 16:00:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "typedef.h"
# include "mlx_manip.h"

typedef struct s_textures
{
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_color		f;
	t_color		c;
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
	t_mlx_p			mlx;
	t_window_p		win;
	t_img_p			img_di;
	t_img_p			img_dr;
	t_kb_event_p	kbe;
	t_player_p		player;
	t_map_p			map;
};

int			loop(t_loop_param *param);

#endif
