/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_set_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:54:28 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 17:56:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_manip.h"

void	tm_set_texture(t_img_descriptor_p id, t_img_p img, int index)
{
	if (index < 0 || index > ID_LENGHT)
		return ;
	id->imgs[index] = img;
}
