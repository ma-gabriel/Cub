/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manip.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:19:44 by gcros             #+#    #+#             */
/*   Updated: 2024/11/19 16:08:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_MANIP_H
# define TEXTURE_MANIP_H

# include "mlx_manip.h"
# include "defines.h"

enum e_img_descriptor
{
	id_display,
	id_buffer,
	id_texture_e,
	id_texture_w,
	id_texture_s,
	id_texture_n,
	id_lenght,
};

# define ID_LENGHT id_lenght

struct s_img_descriptor
{
	t_img_p	imgs[ID_LENGHT];
};

int		tm_init(t_img_descriptor_p id);
void	tm_set_texture(t_img_descriptor_p id, t_img_p img, int index);
t_img_p	tm_get_texture(t_img_descriptor_p id, int index);

#endif