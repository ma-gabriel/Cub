/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:05:23 by geymat            #+#    #+#             */
/*   Updated: 2024/09/02 21:14:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
#include "map_checks.h"
#include "struct.h"
#include "mlx_manip.h"
#include "unistd.h"
#include "mlx.h"
#include "kb_event.h"

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
			mm_img_putpixel_s(&img->img, i, j,
				(t_color){.r = i ^ j, .b = 75, .g = i * j});
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

	if (!check_arg(argc, argv[1]))
		return (1);
	mlx = mm_mlx_new();
	win = mm_window_new(mlx, 1000, 600, "test");
	img = mm_image_new(mlx, 1000, 600);
	frac = gen_frac(mlx, 1000, 600);
	kb_set_event(win);
	if (struct_init(mlx, win, &game, argv[1]) == 1)
	{
		mm_window_delete(win);
		mm_mlx_delete(mlx);
		return (1);
	}
	t_loop_param lparam = {.mlx = mlx, .img = img, .win = win, .frac = frac};
	mlx_loop_hook(mlx, loop, &lparam);
	mlx_loop(mlx);
	strs_free(game.map);
	destroy_all_textures(&game);
	mm_image_delete(img);
	mm_image_delete(frac);
	mm_window_delete(win);
	mm_mlx_delete(mlx);
	return (0);
}

/*int	main(void)
{
	t_mlx_p		mlx = mm_mlx_new();
	t_window_p	win = mm_window_new(mlx, 1000, 600, "test");
	t_image_p	img = mm_image_new(mlx, 1000, 600);
	t_loop_param lparam = {.mlx = mlx, .img = img, .win = win};

	mlx_loop_hook(mlx, loop, &lparam);
	mlx_loop(mlx);
	mm_image_delete(img);
	mm_window_delete(win);
	mm_mlx_delete(mlx);
}*/
