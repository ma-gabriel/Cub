/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:07:39 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 14:10:32 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"

int	pl_init(t_player_p player, t_vec2 pos, double a)
{
	*player = (t_player){.pos = pos, .angle = a};
	return (0);
}
