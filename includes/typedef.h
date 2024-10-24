/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:00:43 by gcros             #+#    #+#             */
/*   Updated: 2024/10/24 15:24:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_cub			t_cub;
typedef struct s_cub			*t_cub_p;

typedef struct s_kb_event		t_kb_event;
typedef t_kb_event				*t_kb_event_p;

typedef struct s_player			t_player;
typedef struct s_player			*t_player_p;

typedef struct s_vec2			t_vec2;
typedef struct s_loop_param		t_loop_param;

typedef struct s_rc_event		t_rc_event;
typedef struct s_rc_event		*t_rc_event_p;
typedef struct s_rc_buf			t_rc_buf;
typedef struct s_rc_buf			*t_rc_buf_p;
typedef struct s_raycast		t_raycast;
typedef struct s_raycast		*t_raycast_p;
typedef struct s_rc_sett		t_rc_sett;
typedef struct s_rc_sett		*t_rc_sett_p;

typedef struct s_cell_flag		t_cell_flag;

typedef struct s_map			t_map;
typedef struct s_map			*t_map_p;

typedef struct s_minimap		t_minimap;
typedef struct s_minimap		*t_minimap_p;

typedef struct s_window			t_window;
typedef t_window				*t_window_p;

typedef struct s_image			t_image;
typedef t_image					*t_image_p;

typedef struct s_img			t_img;
typedef t_img					*t_img_p;

typedef void*					t_mlx_p;
typedef void*					t_win_p;

typedef struct s_color			t_color;

typedef struct s_img_descriptor	t_img_descriptor;
typedef struct s_img_descriptor	*t_img_descriptor_p;

#endif