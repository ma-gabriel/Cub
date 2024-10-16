/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:51:34 by gcros             #+#    #+#             */
/*   Updated: 2024/10/17 01:11:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "cub.h"
#include "mlx_manip.h"
#include "texture_manip.h"
#include "mem.h"
#include "kb_event.h"
#include "struct.h"
#include "map_checks.h"
#include "map_manip.h"
#include "stdio.h"


static int	load_file(t_cub_p cub, char *file);
static int	gen_all_img(t_cub_p cub);
void		strs_free(char **strs);

int	cub_init(t_cub_p cub, char *file)
{
	ft_bzero(cub, sizeof(*cub));
	cub->mlx = mm_mlx_new();
	if (cub->mlx == NULL)
		return (1);
	cub->win = mm_window_new(cub->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (cub->win == NULL)
		return (1);
	tm_init(&cub->id);
	if (load_file(cub, file))
		return (1);
	if (gen_all_img(cub))
		return (1);
	kb_set_event(cub->win, &cub->kbe);
	pl_init(&cub->player, cub->map.start_pos, cub->map.start_orient);
	if (minimap_init(&cub->minimap,
			tm_get_texture(&cub->id, id_minimap), 40, 40))
		return (1);
	return (0);
}

static int	gen_all_img(t_cub_p cub)
{
	t_img_p	tmp;

	tmp = mm_img_new(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	tm_set_texture(&cub->id, tmp, id_display);
	tmp = mm_img_new(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	tm_set_texture(&cub->id, tmp, id_buffer);
	tmp = mm_img_new(cub->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	tm_set_texture(&cub->id, tmp, id_minimap);
	return (0);
}

static int	load_file(t_cub_p cub, char *file)
{
	t_parse	parse;
	int		e;

	e = 0;
	ft_bzero(&parse, sizeof(parse));
	if (struct_init(cub->mlx, cub->win, &parse, file))
		return (1);
	tm_set_texture(&cub->id, parse.textures.no, id_texture_n);
	tm_set_texture(&cub->id, parse.textures.we, id_texture_w);
	tm_set_texture(&cub->id, parse.textures.ea, id_texture_e);
	tm_set_texture(&cub->id, parse.textures.so, id_texture_s);
	e |= map_parse(&cub->map, parse.map);
	strs_free(parse.map);
	return (e);
}
