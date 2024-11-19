/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cell_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:27:16 by gcros             #+#    #+#             */
/*   Updated: 2024/11/19 16:18:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_manip.h"

int	map_cell_setting(t_cell_type type, size_t mask)
{
	static t_cell_attr	tmp[CT_LENGHT] = {
	[ct_void] = {0},
	[ct_wall] = {cf_cast},
	[ct_floor] = {0},
	[ct_unknow] = {0},
	[ct_oob] = {cf_oob | cf_cast},
	};

	if (type > CT_LENGHT || type < 0)
		type = ct_unknow;
	return (tmp[type].value & mask);
}
