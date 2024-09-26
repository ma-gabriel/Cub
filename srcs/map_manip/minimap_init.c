/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:47:33 by gcros             #+#    #+#             */
/*   Updated: 2024/09/26 14:50:28 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"

int	minimap_init(t_minimap_p minimap, int width, int height)
{
	minimap->width = width;
	minimap->height = height;
	return (0);
}
