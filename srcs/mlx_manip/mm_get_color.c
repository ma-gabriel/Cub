/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:13:31 by gcros             #+#    #+#             */
/*   Updated: 2024/08/21 13:40:38 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"

inline t_color	mm_get_color(register int a,
	register int r,
	register int g,
	register int b)
{
	return ((t_color){.value = (a << 24 | r << 16 | g << 8 | b)});
}
