/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:41:19 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 21:04:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MANIP_H
# define CUB_MANIP_H

# include "typedef.h"
# include "struct.h"
# include <sys/types.h>

void		cm_set_sky(t_img_p img, const t_color color);
void		cm_set_ground(t_img_p img, const t_color color);

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
void		cm_put_line(t_img_p img, t_rc_event_p rc, int x);


#endif