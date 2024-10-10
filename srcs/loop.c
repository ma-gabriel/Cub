/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/03 12:32:57 by gcros            ###   ########.fr       */
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

#include <sys/time.h>

int	benchmark_1(t_loop_param *param, int t);

int	loop(t_loop_param *param)
{
	static int		t = 0;
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	if (param->kbe->esc)
		mlx_loop_end(param->mlx);
	kb_mouse_update(param->win, param->kbe);
	pl_update(param->player, param->kbe, param->map);
	minimap_update(param->minimap, param->kbe);
	benchmark_1(param, t);
	minimap_draw(param->minimap, param->map, param->player);
	gettimeofday(&end, NULL);
	if (t % 100 == 0)
		printf("frame time: %ld\n", (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
	mm_img_display(param->img_dr, param->win, 0, 0);
	mm_img_display(param->minimap->img, param->win, 1000, 400);
	ft_memswap(&param->img_di, &param->img_dr, sizeof(param->img_dr));
	//usleep(100000);
	t++;
	return (0);
}

int	benchmark_1(t_loop_param *param, int t)
{
	const t_img_p	img_dr = param->img_dr;
	const t_img_p	img_di = param->img_di;
	int				i;
	int				j;

	(void) t;
	j = 0;
	(void) j;
	mm_img_set_bg(img_dr, (t_color){.value = 0x0});
	map_draw(param->map, img_dr);
	pl_draw(param->player, img_dr, param->map);
	i = 0;
	while (i < 750)
	{
		cm_put_line(img_dr,
			&(t_rc_event){.img = img_di,
			.dist = .75,
			.offset = (double)(i / 750.)}, i + param->kbe->mouse_x - 750. * .5);
		i += 1;
	}
	//pl_print(param->player);
	return (0);
}

/*	test fisheye
		cm_put_line(img,
			&(t_rc_event){.img = frac,
			.dist = (i / 100.) + 1,
			.offset = (i / 100.)}, i + 100);
*/