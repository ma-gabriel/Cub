/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:01 by gcros             #+#    #+#             */
/*   Updated: 2024/09/04 19:44:49 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MANIP_H
# define MAP_MANIP_H

# include "draw.h"

void		map_fill(t_img_p img, char **map);
t_image_p	map_to_image(t_mlx_p mlx, char **map, int width, int height);

#endif
