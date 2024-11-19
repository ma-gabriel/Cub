/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:05:23 by geymat            #+#    #+#             */
/*   Updated: 2024/11/05 14:34:05 by gcros            ###   ########.fr       */
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
#include "cub.h"

int	main(int argc, char **argv)
{
	t_cub				cub;

	if (!check_arg(argc, argv[1]))
		return (1);
	if (cub_init(&cub, argv[1]))
		return (cub_destroy(&cub), 1);
	mlx_loop_hook(cub.mlx, loop, &cub);
	mlx_loop(cub.mlx);
	cub_destroy(&cub);
	printf("Total frames during the session : %ld\n", cub.count);
	return (0);
}
