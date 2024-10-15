/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:05:23 by geymat            #+#    #+#             */
/*   Updated: 2024/10/15 18:36:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "map_checks.h"
#include "struct.h"
#include "mlx_manip.h"
#include "mlx.h"
#include "kb_event.h"
#include "cub_manip.h"
#include "map_manip.h"
#include "player_manip.h"
#include "texture_manip.h"

void	destroy_all_textures(t_thegame *game);

static void	strs_free(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

t_image_p	gen_frac(t_mlx_p mlx, int width, int height)
{
	t_image_p	img;
	int			j;
	int			i;

	img = mm_image_new(mlx, width, height);
	if (img == NULL)
		return (NULL);
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			mm_img_putpixel(&img->img, i, j,
				(t_color){.r = i * j, .b = i * j, .g = i + j});
			i++;
		}
		j++;
	}
	return (img);
}

int	main(int argc, char **argv)
{
	t_thegame			game;
	t_mlx_p				mlx;
	t_window_p			win;
	t_img_p				img1;
	t_img_p				img2;
	t_img_descriptor	id;
	t_img_p				minimapimg;
	t_minimap			minimap;
	t_kb_event			kbe;
	t_map				map;
	t_player			player;

	if (!check_arg(argc, argv[1]))
		return (1);
	mlx = mm_mlx_new();
	win = mm_window_new(mlx, 1500, 700, "test");
	img1 = mm_img_new(mlx, 1500, 700);
	img2 = mm_img_new(mlx, 1500, 700);
	minimapimg = mm_img_new(mlx, 400, 400);
	minimap_init(&minimap, minimapimg, 40, 40);
	kb_set_event(win, &kbe);
	tm_init(&id);
	if (struct_init(mlx, win, &game, argv[1]) == 1)
	{
		mm_window_delete(win);
		mm_mlx_delete(mlx);
		return (1);
	}
	tm_set_texture(&id, img1, id_display);
	tm_set_texture(&id, img2, id_buffer);
	tm_set_texture(&id, minimapimg, id_minimap);
	tm_set_texture(&id, &game.textures.no, id_texture_n);
	tm_set_texture(&id, &game.textures.we, id_texture_w);
	tm_set_texture(&id, &game.textures.ea, id_texture_e);
	tm_set_texture(&id, &game.textures.so, id_texture_s);
	map_parse(&map, game.map);
	pl_init(&player, map.start_pos, map.start_orient);
	t_loop_param	lparam = {.mlx = mlx, .map = &map,
		.win = win, .kbe = &kbe, .minimap = &minimap,
		.player = &player, .id = &id};
	mlx_loop_hook(mlx, loop, &lparam);
	mlx_loop(mlx);

	strs_free(game.map);
	destroy_all_textures(&game);

	mm_window_delete(win);
	mm_mlx_delete(mlx);
	free(map.data);
	return (0);
}
