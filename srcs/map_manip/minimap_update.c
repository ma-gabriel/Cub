/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:52:11 by gcros             #+#    #+#             */
/*   Updated: 2024/09/26 22:56:38 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"
#include "kb_event.h"

void	minimap_update(t_minimap_p minimap, t_kb_event_p kbe)
{
	static int	last_key[2];

	if (kb_get_event(kbe, KB_UP))
	{
		if (last_key[0] == 0)
		{
			last_key[0] = 1;
			minimap->width++;
			minimap->height++;
		}
	}
	else
		last_key[0] = 0;
	if (kb_get_event(kbe, KB_DOWN))
	{
		if (last_key[1] == 0)
		{
			last_key[1] = 1;
			minimap->width--;
			minimap->height--;
		}
	}
	else
		last_key[1] = 0;
}
