/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/11/20 14:22:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "cub_manip.h"
#include "raycast_manip.h"
#include "player_manip.h"
#include "map_manip.h"
#include "kb_event.h"
#include "math.h"
#include "put.h"
#include "mlx.h"
#include "draw.h"
#include "libft.h"
#include "texture_manip.h"
#include "cub.h"

int		draw(t_cub_p cub);
void	gen_frac(t_img_p img, size_t off);
void	update(t_cub_p cub);

int	loop(t_cub_p cub)
{
	t_color color;

	if (kb_get_event(&cub->kbe, KB_ESC) || cub->count == 10000000)
		mlx_loop_end(cub->mlx);
	update(cub);
	draw(cub);
	if (cub->count & 1)
		color = (t_color){.r = 255, .a = 200};
	else
		color = (t_color){.b = 255, .a = 200};
	draw_rect_a(tm_get_texture(&cub->id, id_buffer), (t_vec2){0, 0},
		(t_vec2){tm_get_texture(&cub->id, id_buffer)->width,
			tm_get_texture(&cub->id, id_buffer)->height} , color);
	mm_img_display(tm_get_texture(&cub->id, id_buffer), cub->win, 0, 0);
	ft_memswap((cub->id.imgs + id_buffer),
		(cub->id.imgs + id_display),
		sizeof(t_img_p));
	cub->count++;
	return (0);
}

void	update(t_cub_p cub)
{
	kb_mouse_update(cub->win, &cub->kbe);
	pl_update(&cub->player, &cub->kbe, &cub->map);
	map_update(&cub->map, &cub->kbe, cub);
	minimap_update(&cub->minimap, &cub->kbe);
	if (kb_get_event(&cub->kbe, 'm'))
		cub->delay += 1000;
	if (kb_get_event(&cub->kbe, 'n'))
		cub->delay -= 1000;
	if (cub->delay <= 0)
		cub->delay = 1;
}

int	draw(t_cub_p cub)
{
	const t_img_p	img_dr = tm_get_texture(&cub->id, id_buffer);
	const t_img_p	img_di = tm_get_texture(&cub->id, id_display);

	(void) img_di;
	rcb_wizard(&cub->rcb, &cub->map, &cub->player, &cub->id);
	if (kb_get_event(&cub->kbe, MAP_TRIG))
	{
		map_draw(&cub->map, img_dr);
		pl_draw(&cub->player, img_dr, &cub->map);
		rcb_draw(&cub->rcb, img_dr, &cub->map);
	}
	else
	{
		cm_set_ground(img_dr, cub->floor);
		cm_set_sky(img_dr, cub->ceiling);
		rcb_applie(&cub->rcb, img_dr);
		draw_cross(img_dr);
		minimap_draw(&cub->minimap, &cub->map, &cub->player, &cub->rcb);
		mm_img_to_img(tm_get_texture(&cub->id, id_minimap),
			tm_get_texture(&cub->id, id_buffer), 0, 0);
	}
	return (0);
}
