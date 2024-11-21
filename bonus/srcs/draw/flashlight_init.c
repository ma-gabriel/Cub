/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashlight_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:16:23 by gcros             #+#    #+#             */
/*   Updated: 2024/11/21 15:31:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flashlight.h"

int	flashlight_init(t_flashlight_p flashlight)
{
	flashlight->center = (t_vec2){0.5, 0.5};
	flashlight->max_a = 20.;
	flashlight->size = 0.2;
	return (0);
}
