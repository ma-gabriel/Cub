/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:47:53 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 19:01:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_manip.h"
#include "map_manip.h"
#include "math.h"

void	pl_draw(t_player_p player, t_img_p img, t_map_p map)
{
	const t_vec2	ratio = (t_vec2){img->width / (double)map->width,
		img->height / (double)map->height};
	const t_vec2	size = (t_vec2){ratio.x * player->size,
		ratio.y * player->size};

	draw_rect(img, (t_vec2){((player->pos.x) - (player->size * .5)) * ratio.x,
		((player->pos.y - (player->size * .5)) * ratio.y)},
		size, (t_color){.value = 0x00FF00FF});
	draw_line(img, (t_vec2){player->pos.x * ratio.x, player->pos.y * ratio.y},
		(t_vec2){.x = cos(player->angle) * ratio.x + player->pos.x * ratio.x,
		.y = sin(player->angle) * ratio.y + player->pos.y * ratio.y},
		(t_color){.value = 0x0000FF00});
}
