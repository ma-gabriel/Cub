/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_window_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:48:54 by gcros             #+#    #+#             */
/*   Updated: 2024/10/28 21:20:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include <stdlib.h>
#include "put.h"
#include "mlx.h"
#include "defines.h"

t_window_p	mm_window_new(t_mlx_p mlx, int width, int height, char *name)
{
	t_window_p	win;

	win = malloc(sizeof(t_window));
	if (win == NULL)
	{
		ft_putendl_fd(ERR"mm_window_new: malloc: NULL pointer returned", 2);
		return (NULL);
	}
	win->mlx_ptr = mlx;
	win->win_ptr = mlx_new_window(mlx, width, height, name);
	if (win->win_ptr == NULL)
	{
		ft_putendl_fd(ERR"mm_window_new: mlx_new_window: NULL pointer returned",
			2);
		free(win);
		return (NULL);
	}
	return (win);
}
