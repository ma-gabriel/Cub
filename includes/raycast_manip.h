/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_manip.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:45:46 by gcros             #+#    #+#             */
/*   Updated: 2024/10/30 13:57:34 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MANIP_H
# define RAYCAST_MANIP_H

# include <sys/types.h>
# include "typedef.h"
# include "struct.h"
# include "map_manip.h"

struct s_rc_event
{
	t_img_p	img;
	double	dist;
	double	offset;
	t_vec2	collision;
	t_vec2	start;
};

struct s_raycast
{
	double		angle;
	int			face;
	double		dist;
	t_vec2		pos;
	double		offset;
};

struct s_rc_buf
{
	t_rc_event	*buf;
	size_t		size;
};

struct s_rc_sett
{
	double		angle;
	double		max;
	t_vec2		start;
	t_vec2		delta;
	t_cell_attr	attributes;
};

int			rcb_init(t_rc_buf_p rcb, size_t size);
void		rcb_destroy(t_rc_buf_p rcb);
void		rcb_applie(t_rc_buf_p rcb, t_img_p img);
void		rcb_wizard(t_rc_buf_p rcb, t_map_p map,
				t_player_p player, t_img_descriptor_p id);
t_raycast	rc_throw(t_map_p map, t_rc_sett rcs);
void		rcb_draw(t_rc_buf_p rcb, t_img_p img, t_map_p map);

#endif