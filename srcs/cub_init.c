/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:51:34 by gcros             #+#    #+#             */
/*   Updated: 2024/11/19 16:10:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "struct.h"
#include "mem.h"
#include "kb_event.h"
#include "map_checks.h"
#include "libft.h"

static int	load_file(t_cub_p cub, char *file);
static int	gen_all_img(t_cub_p cub);
void		ft_strsfree(char **strs);
static int	check_id(t_img_descriptor_p id);

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
	if (rcb_init(&cub->rcb, WIN_WIDTH / THICKNESS_RAYS))
		return (1);
	check_id(&cub->id);
	cub->delay = 1;
	return (0);
}

static int	check_id(t_img_descriptor_p id)
{
	int	i;

	i = 0;
	while (i < ID_LENGHT)
	{
		if (id->imgs[i] == NULL)
		{
			ft_putstr_fd(ERR "cub_init: check_id: bad alloc ", 2);
			ft_putnbr_fd(i, 2);
			ft_putendl_fd("", 2);
		}
		i++;
	}
	return (0);
}

static int	gen_all_img(t_cub_p cub)
{
	t_img_p	tmp;
	int		err;

	err = 0;
	tmp = mm_img_new(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	err |= tmp == NULL;
	tm_set_texture(&cub->id, tmp, id_display);
	tmp = mm_img_new(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	err |= tmp == NULL;
	tm_set_texture(&cub->id, tmp, id_buffer);
	return (err);
}

static int	load_file(t_cub_p cub, char *file)
{
	t_parse	parse;
	int		e;

	e = 0;
	ft_bzero(&parse, sizeof(parse));
	if (parsing_init(cub->mlx, cub->win, &parse, file))
		return (1);
	tm_set_texture(&cub->id, parse.textures.no, id_texture_n);
	tm_set_texture(&cub->id, parse.textures.we, id_texture_w);
	tm_set_texture(&cub->id, parse.textures.ea, id_texture_e);
	tm_set_texture(&cub->id, parse.textures.so, id_texture_s);
	cub->floor = parse.textures.f;
	cub->ceiling = parse.textures.c;
	e |= map_parse(&cub->map, parse.map);
	ft_strsfree(parse.map);
	return (e);
}
