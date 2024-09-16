/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:05:23 by geymat            #+#    #+#             */
/*   Updated: 2024/09/16 16:09:20 by gcros            ###   ########.fr       */
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
	t_thegame	game;
	t_mlx_p		mlx;
	t_window_p	win;
	t_image_p	img;
	t_image_p	frac;
	t_image_p	sky;
	t_image_p	ground;
	t_kb_event	kbe;
	t_map		map;
	t_player	player;

	if (!check_arg(argc, argv[1]))
		return (1);
	mlx = mm_mlx_new();
	win = mm_window_new(mlx, 1500, 600, "test");
	img = mm_image_new(mlx, 1500, 600);
	sky = mm_image_new(mlx, 1500, 300);
	ground = mm_image_new(mlx, 1500, 300);
	frac = gen_frac(mlx, 256, 256);
	mm_img_set_bg(&sky->img, (t_color){.value = 0x000000FF});
	mm_img_set_bg(&ground->img, (t_color){.value = 0x00FF0000});
	draw_rect(&img->img, (t_vec2){10, 10}, (t_vec2){1000, 1000}, (t_color){.value = 0x00FF0000});
	kb_set_event(win, &kbe);
	pl_init(&player, (t_vec2){0, 0}, 0);
	if (struct_init(mlx, win, &game, argv[1]) == 1)
	{
		mm_window_delete(win);
		mm_mlx_delete(mlx);
		return (1);
	}
	map_parse(&map, game.map);
	map_fill(&map, &img->img);
	t_loop_param	lparam = {.mlx = mlx, .img = &img->img,
		.win = win, .frac = &frac->img, .kbe = &kbe,
		.sky = &sky->img, .ground = &ground->img, .player = &player};
	mlx_loop_hook(mlx, loop, &lparam);
	mlx_loop(mlx);
	strs_free(game.map);
	destroy_all_textures(&game);
	mm_image_delete(ground);
	mm_image_delete(sky);
	mm_image_delete(img);
	mm_image_delete(frac);
	mm_window_delete(win);
	mm_mlx_delete(mlx);
	return (0);
}
