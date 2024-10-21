/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cell_get_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:15:19 by gcros             #+#    #+#             */
/*   Updated: 2024/10/21 22:48:05 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"

t_cell_type	map_cell_get_type(char c)
{
	if (c == ' ')
		return (ct_void);
	if (c == 'N')
		return (ct_floor);
	if (c == 'W')
		return (ct_floor);
	if (c == 'E')
		return (ct_floor);
	if (c == 'S')
		return (ct_floor);
	if (c == '0')
		return (ct_floor);
	if (c == '1')
		return (ct_wall);
	if (c == 'C')
		return (ct_door_close);
	if (c == 'O')
		return (ct_door_open);
	return (ct_unknow);
}
