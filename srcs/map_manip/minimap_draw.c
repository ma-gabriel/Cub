/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:52:07 by gcros             #+#    #+#             */
/*   Updated: 2024/10/01 17:17:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "player_manip.h"
#include "math.h"
#include "num.h"
#include "libft.h"

void	dr_pl(t_minimap_p minimap, t_player_p player,
			t_img_p img, const t_vec2 ratio);

void	minimap_draw(t_minimap_p minimap, t_map_p map,
		t_player_p player, t_img_p img)
{
	const t_vec2	ratio
		= (t_vec2){(double)img->width / (double)(minimap->width),
		(double)img->height / (double)(minimap->height)};
	double			i;
	double			j;

	mm_img_set_bg(img, cell_get_color(ct_unknow));
	j = -.5 * (minimap->height & 1);
	printf("ratio: {x: %ld, y: %ld}\n", minimap->width, minimap->height);
	while (j < minimap->height + 1.)
	{
		i =  -.5 * (minimap->width & 1);
		while (i < minimap->width + 1.)
		{
			draw_rect(img,
				(t_vec2){((i - ft_get_real(player->pos.x)) * ratio.x),
				((j - ft_get_real(player->pos.y)) * ratio.y)},
				(t_vec2){ratio.x + 1., ratio.y + 1.},
				cell_get_color(map_get_cell(map,
						floor(i + player->pos.x - (double)minimap->width / 2.),
						floor(j + player->pos.y - (double)minimap->height / 2.))));
			i++;
		}
		j++;
	}
	dr_pl(minimap, player, img, ratio);
}

void	dr_pl(t_minimap_p minimap, t_player_p player,
			t_img_p img, const t_vec2 ratio)
{
	const t_vec2	size = (t_vec2){ratio.x * PLAYER_SIZE,
		ratio.y * PLAYER_SIZE};

	draw_rect(img, (t_vec2){
		.x = ((minimap->width / 2.) - (PLAYER_SIZE / 2.)) * ratio.x,
		.y = ((minimap->height / 2.) - (PLAYER_SIZE / 2.)) * ratio.y},
		size, (t_color){.value = 0x00FF00FF});
	draw_line(img, (t_vec2){
		.x = minimap->width / 2. * ratio.x,
		.y = minimap->height / 2. * ratio.y},
		(t_vec2){
		.x = cos(player->angle) * ratio.x + minimap->width / 2. * ratio.x,
		.y = sin(player->angle) * ratio.y + minimap->height / 2. * ratio.y},
		(t_color){0x0000FF00});
}
