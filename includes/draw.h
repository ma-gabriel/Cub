/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:14:43 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 16:16:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "typedef.h"

void	draw_rect(t_img_p img, t_vec2 co, t_vec2 size, t_color color);
void	draw_line(t_img_p img, t_vec2 start, t_vec2 end, t_color color);

#endif
