/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_window_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:49:03 by gcros             #+#    #+#             */
/*   Updated: 2024/08/20 17:43:56 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mlx.h"
#include <stdlib.h>

void	mm_window_delete(t_window_p win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	free(win);
}
