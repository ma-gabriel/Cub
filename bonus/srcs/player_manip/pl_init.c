/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:07:39 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 19:00:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "math.h"

int	pl_init(t_player_p player, t_vec2 pos, double a)
{
	*player = (t_player){
		.pos = pos,
		.angle = a,
		.fov = M_PI / 2,
		.size = PLAYER_SIZE
	};
	return (0);
}
