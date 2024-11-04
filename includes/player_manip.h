/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manip.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:11:19 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 18:59:59 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MANIP_H
# define PLAYER_MANIP_H

# include "typedef.h"
# include "struct.h"

# define PLAYER_SIZE 0.5
# define PLAYER_MOVE 0.02
# define PLAYER_TURN 0.02
# ifndef M_PI
#  define M_PI		3.14159265358979323846	/* pi */
# endif
# ifndef M_PI_2
#  define M_PI_2		1.57079632679489661923	/* pi/2 */
# endif

struct s_player
{
	double	angle;
	double	fov;
	t_vec2	pos;
	double	size;
};

int		pl_init(t_player_p player, t_vec2 pos, double a);
void	pl_update(t_player_p player, t_kb_event_p kbe, t_map_p map);
void	pl_draw(t_player_p player, t_img_p img, t_map_p map);
void	pl_setpos(t_player_p player, double x, double y);
void	pl_print(t_player_p player);
void	pl_turnl(t_player_p player);
void	pl_turnr(t_player_p player);
void	pl_walk_front(t_player_p player, t_map_p map);
void	pl_walk_back(t_player_p player, t_map_p map);
void	pl_walk_left(t_player_p player, t_map_p map);
void	pl_walk_right(t_player_p player, t_map_p map);
void	pl_collide(t_player_p player, t_map_p map, t_vec2 npos, double angle);

#endif