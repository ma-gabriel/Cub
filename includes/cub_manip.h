/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:41:19 by gcros             #+#    #+#             */
/*   Updated: 2024/09/02 16:42:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MANIP_H
# define CUB_MANIP_H

# include "mlx_manip.h"

void	cm_set_sky(t_img_p img, const t_color color);
void	cm_set_ground(t_img_p img, const t_color color);

#endif