/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:53:01 by gcros             #+#    #+#             */
/*   Updated: 2024/10/25 17:39:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "typedef.h"
# include "texture_manip.h"
# include "kb_event.h"
# include "player_manip.h"
# include "map_manip.h"
# include "raycast_manip.h"

struct s_cub
{
	t_mlx_p				mlx;
	t_win_p				win;
	t_kb_event			kbe;
	t_player			player;
	t_map				map;
	t_minimap			minimap;
	t_img_descriptor	id;
	t_rc_buf			rcb;
	t_color				floor;
	t_color				ceiling;
	int					delay;
	size_t				count;
};

int		cub_init(t_cub_p cub, char *file);
void	cub_destroy(t_cub_p cub);

#endif