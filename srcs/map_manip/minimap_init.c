/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:47:33 by gcros             #+#    #+#             */
/*   Updated: 2024/10/03 12:46:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include <stdio.h>

int	minimap_init(t_minimap_p minimap, t_img_p img, int width, int height)
{
	minimap->width = width;
	minimap->height = height;
	minimap->img = img;
	return (0);
}
