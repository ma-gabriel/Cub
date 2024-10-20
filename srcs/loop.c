/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/20 18:00:59 by gcros            ###   ########.fr       */
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
#include <sys/time.h>
#include "cub.h"

int	benchmark_1(t_cub_p cub, int t);

int	loop(t_cub_p cub)
{
	static int		t = 0;
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	if (kb_get_event(&cub->kbe, KB_ESC) || t == 100000)
		mlx_loop_end(cub->mlx);
	kb_mouse_update(cub->win, &cub->kbe);
	pl_update(&cub->player, &cub->kbe, &cub->map);
	minimap_update(&cub->minimap, &cub->kbe);
	benchmark_1(cub, t);
	minimap_draw(&cub->minimap, &cub->map, &cub->player, &cub->rcb);
	gettimeofday(&end, NULL);
	if (t % 100 == 0)
		printf("frame time: %ld\n", (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
	mm_img_display(tm_get_texture(&cub->id, id_buffer), cub->win, 0, 0);
	mm_img_display(tm_get_texture(&cub->id, id_minimap), cub->win, 1000, 300);
	ft_memswap((cub->id.imgs + id_buffer),
		(cub->id.imgs + id_display),
		sizeof(t_img_p));
	//usleep(100000);
	t++;
	return (0);
}

int	benchmark_1(t_cub_p cub, int t)
{
	const t_img_p	img_dr = tm_get_texture(&cub->id, id_buffer);
	const t_img_p	img_di = tm_get_texture(&cub->id, id_display);

	(void) t, (void) img_di;
	rcb_wizard(&cub->rcb, &cub->map, &cub->player, &cub->id);
	if (kb_get_event(&cub->kbe, KB_TAB))
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
	}
	return (0);
}
