/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:52:07 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 20:46:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "player_manip.h"
#include "math.h"
#include "num.h"
#include "libft.h"
#include "draw.h"

void	dr_pl(t_minimap_p minimap, t_player_p player, const t_vec2 ratio);
void	dr_mp(t_minimap_p minimap, t_map_p map,
			t_vec2 center, const t_vec2 ratio);

void	minimap_draw(t_minimap_p minimap, t_map_p map,
		t_player_p player)
{
	const t_vec2	ratio
		= (t_vec2){(double)minimap->img->width / (double)(minimap->width),
		(double)minimap->img->height / (double)(minimap->height)};

	mm_img_set_bg(minimap->img, cell_get_color(ct_unknow));
	dr_mp(minimap, map, player->pos, ratio);
	dr_pl(minimap, player, ratio);
}

void	dr_mp(t_minimap_p minimap, t_map_p map,
			const t_vec2 center, const t_vec2 ratio)
{
	double		i;
	double		j;
	const int	h = minimap->height;
	const int	w = minimap->width;

	j = -.5 * (h & 1);
	while (j < h + 1.)
	{
		i =  -.5 * (w & 1);
		while (i < w + 1.)
		{
			draw_rect(minimap->img,
				(t_vec2){((i - ft_get_real(center.x)) * ratio.x),
				((j - ft_get_real(center.y)) * ratio.y)},
				(t_vec2){ratio.x + 1., ratio.y + 1.},
				cell_get_color(map_get_cell_s(map,
						floor(i + center.x - (double)w * .5),
						floor(j + center.y - (double)h * .5))));
			i++;
		}
		j++;
	}
}

void	dr_pl(t_minimap_p minimap, t_player_p player, const t_vec2 ratio)
{
	const t_vec2	size = (t_vec2){ratio.x * PLAYER_SIZE,
		ratio.y * PLAYER_SIZE};

	draw_rect(minimap->img, (t_vec2){
		.x = ((minimap->width * .5) - (PLAYER_SIZE * .5)) * ratio.x,
		.y = ((minimap->height * .5) - (PLAYER_SIZE * .5)) * ratio.y},
		size, (t_color){.value = 0x7FFF00FF});
	draw_line(minimap->img, (t_vec2){
		.x = minimap->width * .5 * ratio.x - .5,
		.y = minimap->height * .5 * ratio.y - .5},
		(t_vec2){
		.x = cos(player->angle) * ratio.x + minimap->width * .5 * ratio.x,
		.y = sin(player->angle) * ratio.y + minimap->height * .5 * ratio.y},
		(t_color){.value = 0x7F00FF00});
}
