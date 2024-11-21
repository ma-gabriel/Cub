/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashlight.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:24:58 by gcros             #+#    #+#             */
/*   Updated: 2024/11/21 15:17:07 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLASHLIGHT_H
# define FLASHLIGHT_H

# include "typedef.h"
# include "struct.h"

struct s_flashlight
{
	char	max_a;
	t_vec2	center;
	double	size;
};

void	draw_light(t_flashlight flashlight, t_img_p img);
int		flashlight_init(t_flashlight_p flashlight);

#endif