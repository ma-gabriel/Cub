/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:15:33 by gcros             #+#    #+#             */
/*   Updated: 2024/10/19 14:17:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_PI 3.14159

#include "math.h"

double	ft_norm_angle(double a)
{
	while (a >= 2. * M_PI)
		a -= 2. * M_PI;
	while (a < 0.)
		a += 2. * M_PI;
	return (a);
}
