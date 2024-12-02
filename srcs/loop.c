/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:13:28 by gcros             #+#    #+#             */
/*   Updated: 2024/12/02 12:05:39 by gcros            ###   ########.fr       */
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
	if (kb_get_event(&cub->kbe, KB_ESC))
		mlx_loop_end(cub->mlx);
	update(cub);
	draw(cub);
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
	cm_set_ground(img_dr, cub->floor);
	cm_set_sky(img_dr, cub->ceiling);
	rcb_applie(&cub->rcb, img_dr);
	return (0);
}
