/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 18:37:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "cub_manip.h"
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

int	benchmark_1(t_loop_param *param, int t);

int	loop(t_loop_param *param)
{
	static int		t = 0;
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	if (param->kbe->esc || t == 1000000)
		mlx_loop_end(param->mlx);
	kb_mouse_update(param->win, param->kbe);
	pl_update(param->player, param->kbe, param->map);
	minimap_update(param->minimap, param->kbe);
	benchmark_1(param, t);
	minimap_draw(param->minimap, param->map, param->player);
	gettimeofday(&end, NULL);
	if (t % 100 == 0)
		printf("frame time: %ld\n", (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
	mm_img_display(tm_get_texture(param->id, id_buffer), param->win, 0, 0);
	mm_img_display(param->minimap->img, param->win, 1000, 400);
	ft_memswap((param->id->imgs + id_buffer),
		(param->id->imgs + id_display),
		sizeof(t_img_p));
	//usleep(100000);
	t++;
	return (0);
}

int	benchmark_1(t_loop_param *param, int t)
{
	const t_img_p	img_dr = tm_get_texture(param->id, id_buffer);
	const t_img_p	img_di = tm_get_texture(param->id, id_display);
	int				i;
	int				j;

	(void) t;
	j = 0;
	(void) j;
	if (kb_get_event(param->kbe, KB_TAB))
	{
		map_draw(param->map, img_dr);
		pl_draw(param->player, img_dr, param->map);
	}
	else
	{
		cm_set_ground(img_dr, (t_color){0x00FF7F00});
		cm_set_sky(img_dr, (t_color){0x00005FFF});
		i = 0;
		while (i < 750)
		{
			cm_put_line(img_dr,
				&(t_rc_event){.img = img_di,
				.dist = .75,
				.offset = (double)(i / 750.)}, i + param->kbe->mouse_x - 750. * .5);
			i += 1;
		}
	}
	return (0);
}

/*	test fisheye
		cm_put_line(img,
			&(t_rc_event){.img = frac,
			.dist = (i / 100.) + 1,
			.offset = (i / 100.)}, i + 100);
*/