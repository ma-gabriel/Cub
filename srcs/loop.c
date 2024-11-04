/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/29 19:06:00 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _DEFAULT_SOURCE
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
#include <sys/time.h>
#include "cub.h"

int		benchmark_1(t_cub_p cub);
void	gen_frac(t_img_p img, size_t off);
void	update(t_cub_p cub);

int	loop(t_cub_p cub)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	if (kb_get_event(&cub->kbe, KB_ESC))
		mlx_loop_end(cub->mlx);
	update(cub);
	benchmark_1(cub);
	gettimeofday(&end, NULL);
	if (cub->count % 100 == 0) // norm error line too long but forbidden function so OK
		printf("frame time: %ld\n", (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
	mm_img_display(tm_get_texture(&cub->id, id_buffer), cub->win, 0, 0);
	ft_memswap((cub->id.imgs + id_buffer),
		(cub->id.imgs + id_display),
		sizeof(t_img_p));
	usleep(cub->delay);
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

int	benchmark_1(t_cub_p cub)
{
	const t_img_p	img_dr = tm_get_texture(&cub->id, id_buffer);
	const t_img_p	img_di = tm_get_texture(&cub->id, id_display);

	(void) img_di;
	rcb_wizard(&cub->rcb, &cub->map, &cub->player, &cub->id);
	cm_set_ground(img_dr, cub->floor);
	cm_set_sky(img_dr, cub->ceiling);
	if (kb_get_event(&cub->kbe, KB_TAB))
	{
		map_draw(&cub->map, img_dr);
		pl_draw(&cub->player, img_dr, &cub->map);
		rcb_draw(&cub->rcb, img_dr, &cub->map);
	}
	else
	{
		rcb_applie(&cub->rcb, img_dr);
		draw_cross(img_dr);
		minimap_draw(&cub->minimap, &cub->map, &cub->player, &cub->rcb);
		mm_img_to_img(tm_get_texture(&cub->id, id_minimap),
			tm_get_texture(&cub->id, id_buffer), 0, 0);
	}
	return (0);
}
