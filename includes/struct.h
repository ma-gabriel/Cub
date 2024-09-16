/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:24 by geymat            #+#    #+#             */
/*   Updated: 2024/09/10 17:23:59 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "mlx_manip.h"
# include "kb_event.h"
# include <unistd.h>
# include "defines.h"

typedef struct s_vec2		t_vec2;
typedef struct s_loop_param	t_loop_param;

typedef struct s_sprite
{
	t_img		images[SPRITE_IMGS];
	size_t		index;
}		t_sprite;

typedef struct s_textures
{
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
	t_mlx_p			mlx;
	t_window_p		win;
	t_img_p			img;
	t_img_p			frac;
	t_img_p			sky;
	t_img_p			ground;
	t_kb_event_p	kbe;
	char			**map;
};

int			loop(t_loop_param *param);

#endif
