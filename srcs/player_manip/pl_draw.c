/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:47:53 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 20:46:59 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "map_manip.h"
#include "math.h"

void	pl_draw(t_player_p player, t_img_p img, t_map_p map)
{
	const t_vec2	ratio = (t_vec2){img->width / (double)map->width,
		img->height / (double)map->height};
	const t_vec2	size = (t_vec2){ratio.x * PLAYER_SIZE,
		ratio.y * PLAYER_SIZE};

	draw_rect(img, (t_vec2){((player->pos.x) - (PLAYER_SIZE * .5)) * ratio.x,
		((player->pos.y - (PLAYER_SIZE * .5)) * ratio.y)},
		size, (t_color){.value = 0x00FF00FF});
	draw_line(img, (t_vec2){player->pos.x * ratio.x, player->pos.y * ratio.y},
		(t_vec2){.x = cos(player->angle) * ratio.x + player->pos.x * ratio.x,
		.y = sin(player->angle) * ratio.y + player->pos.y * ratio.y},
		(t_color){.value = 0x0000FF00});
}
