/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_manip.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:45:46 by gcros             #+#    #+#             */
/*   Updated: 2024/10/16 18:47:18 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MANIP_H
# define RAYCAST_MANIP_H

# include <sys/types.h>
# include "typedef.h"
# include "struct.h"

struct s_rc_event
{
	t_img_p	img;
	double	dist;
	double	offset;
	t_vec2	collision;
};

struct s_rc_buf
{
	t_rc_event	*buf;
	size_t		size;
};

int			rcb_init(t_rc_buf_p rcb, size_t size);
void		rcb_destroy(t_rc_buf_p rcb);
void		rcb_draw(t_rc_buf_p rcb, t_img_p img);
void		rcb_wizard(t_rc_buf_p rcb, t_map_p map,
				t_player player, t_img_descriptor_p id);
t_rc_event	rc_throw(t_map_p map, t_vec2 pos,
				double angle, t_img_descriptor_p id);

#endif