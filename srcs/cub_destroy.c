/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:52:26 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 16:42:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "stdlib.h"
#include "raycast_manip.h"

static void	destroy_all_img(t_cub_p cub);

void	cub_destroy(t_cub_p cub)
{
	if (cub->mlx == NULL)
		return ;
	if (cub->win == NULL)
		return ;
	destroy_all_img(cub);
	mm_window_delete(cub->win);
	mm_mlx_delete(cub->mlx);
	rcb_destroy(&cub->rcb);
	free(cub->map.data);
}

static void	destroy_all_img(t_cub_p cub)
{
	size_t	i;

	i = 0;
	while (i < ID_LENGHT)
	{
		if (cub->id.imgs[i])
			mm_img_delete(cub->id.imgs[i], cub->mlx);
		i++;
	}
}
