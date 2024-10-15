/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:57:13 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 18:00:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_manip.h"

t_img_p	tm_get_texture(t_img_descriptor_p id, int index)
{
	if (index < 0 || index > ID_LENGHT)
		return (0);
	return (id->imgs[index]);
}
