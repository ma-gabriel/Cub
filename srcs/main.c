/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:05:23 by geymat            #+#    #+#             */
/*   Updated: 2024/08/21 14:39:31 by gcros            ###   ########.fr       */
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

//int	main(int argc, char **argv)
//{
//	t_thegame	game;

//	ft_bzero(&game, sizeof(game));
//	if (!check_arg(argc, argv[1]))
//		return (1);
//	struct_init(&game, argv[1]);
//	if (game.map)
//		strs_free(game.map);
//	return (0);
//}

void	foo(void)
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
}

int	main(void)
{
	foo();
}
