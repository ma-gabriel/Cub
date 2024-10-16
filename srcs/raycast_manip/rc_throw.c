/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:37:55 by gcros             #+#    #+#             */
/*   Updated: 2024/10/16 18:48:52 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "struct.h"
#include "raycast_manip.h"

t_rc_event	rc_throw(t_map_p map, t_vec2 pos,
				double angle, t_img_descriptor_p id)
{
	(void) map, (void) pos, (void) angle, (void) id;
	return ((t_rc_event){0});
}
