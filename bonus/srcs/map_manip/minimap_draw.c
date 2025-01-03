/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:52:07 by gcros             #+#    #+#             */
/*   Updated: 2024/12/03 15:59:47 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "player_manip.h"
#include "math.h"
#include "num.h"
#include "libft.h"
#include "draw.h"
#include "raycast_manip.h"

static void	draw_pl(t_minimap_p minimap, t_player_p player, const t_vec2 ratio);
static void	draw_mp(t_minimap_p minimap, t_map_p map,
				t_vec2 center, const t_vec2 ratio);
static void	draw_rc(t_minimap_p minimap,
				t_rc_buf_p rcb, t_vec2 ratio, t_vec2 p);

void	minimap_draw(t_minimap_p minimap, t_map_p map,
		t_player_p player, t_rc_buf_p rcb)
{
	const t_vec2	ratio
		= (t_vec2){(double)minimap->img->width / (double)(minimap->width),
		(double)minimap->img->height / (double)(minimap->height)};

	mm_img_set_bg(minimap->img, cell_get_color(ct_unknow));
	draw_mp(minimap, map, player->pos, ratio);
	draw_rc(minimap, rcb, ratio, player->pos);
	draw_pl(minimap, player, ratio);
}

static void	draw_rc(t_minimap_p minimap,
t_rc_buf_p rcb, t_vec2 ratio, t_vec2 center)
{
	const t_vec2	c = {.x = -center.x + (minimap->width * .5),
		.y = -center.y + (minimap->height * .5)};
	size_t			i;
	t_vec2			e;
	t_vec2			s;

	i = 0;
	while (i < rcb->size)
	{
		e = (t_vec2){
			.x = (rcb->buf[i].collision.x + c.x) * ratio.x,
			.y = (rcb->buf[i].collision.y + c.y) * ratio.y};
		s = (t_vec2){
			.x = (rcb->buf[i].start.x + c.x) * ratio.x,
			.y = (rcb->buf[i].start.y + c.y) * ratio.y};
		draw_line(minimap->img, s, e, (t_color){.value = 0x0000FF00});
		i++;
	}
}

static void	draw_mp(t_minimap_p minimap, t_map_p map,
			const t_vec2 center, const t_vec2 ratio)
{
	double		i;
	double		j;
	const int	h = minimap->height;
	const int	w = minimap->width;

	j = -.5 * (h & 1);
	while (j < h + 1.)
	{
		i = -.5 * (w & 1);
		while (i < w + 1.)
		{
			draw_rect(minimap->img,
				(t_vec2){((i - ft_get_real(center.x)) * ratio.x),
				((j - ft_get_real(center.y)) * ratio.y)},
				(t_vec2){ratio.x + 1., ratio.y + 1.},
				cell_get_color(map_get_cell_s(map,
						floor(i + center.x - (double)(w * .5)),
						floor(j + center.y - (double)(h * .5)))));
			i++;
		}
		j++;
	}
}

static void	draw_pl(t_minimap_p minimap, t_player_p player, const t_vec2 ratio)
{
	const t_vec2	size = (t_vec2){ratio.x * player->size,
		ratio.y * player->size};

	draw_rect(minimap->img, (t_vec2){
		.x = ((minimap->width * .5) - (player->size * .5)) * ratio.x,
		.y = ((minimap->height * .5) - (player->size * .5)) * ratio.y},
		size, (t_color){.value = 0x7FFF00FF});
	draw_line(minimap->img, (t_vec2){
		.x = (minimap->width * .5) * ratio.x - .5,
		.y = (minimap->height * .5) * ratio.y - .5},
		(t_vec2){
		.x = cos(player->angle) * ratio.x + (minimap->width * .5) * ratio.x,
		.y = sin(player->angle) * ratio.y + (minimap->height * .5) * ratio.y},
		(t_color){.value = 0x7F0000FF});
}
