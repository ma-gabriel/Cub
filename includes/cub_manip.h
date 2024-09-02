/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:41:19 by gcros             #+#    #+#             */
/*   Updated: 2024/09/03 00:37:07 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MANIP_H
# define CUB_MANIP_H

# include "mlx_manip.h"

typedef struct s_rc_event	t_rc_event;
typedef struct s_rc_event	*t_rc_event_p;

void	cm_set_sky(t_img_p img, const t_color color);
void	cm_set_ground(t_img_p img, const t_color color);

struct s_rc_event
{
	t_img_p	img;
	double	dist;
	double	offset;
};

void	cm_put_line(t_img_p img, t_rc_event_p rc, int x);


#endif