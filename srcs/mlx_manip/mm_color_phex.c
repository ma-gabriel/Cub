/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_color_phex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:23:51 by gcros             #+#    #+#             */
/*   Updated: 2024/10/20 17:59:13 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "mem.h"

void	mm_color_phex(t_color color)
{
	write(2, "0X", 2);
	print_byte(color.a);
	print_byte(color.r);
	print_byte(color.g);
	print_byte(color.b);
}
