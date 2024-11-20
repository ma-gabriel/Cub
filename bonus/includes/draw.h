/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:14:43 by gcros             #+#    #+#             */
/*   Updated: 2024/11/20 20:35:08 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "typedef.h"

void	draw_rect(t_img_p img, t_vec2 co, t_vec2 size, t_color color);
void	draw_line(t_img_p img, t_vec2 start, t_vec2 end, t_color color);
t_color	color_blend(t_color c1, t_color c2);
void	draw_pixel_a(t_img_p img, int x, int y, t_color color);
void	draw_pixel_as(t_img_p img, int x, int y, t_color color);
void	draw_line_a(t_img *img, t_vec2 p1, t_vec2 p2, t_color color);
void	draw_rect_a(t_img_p img, t_vec2 co, t_vec2 size, t_color color);
void	draw_cross(t_img_p img);
void	draw_light(t_img_p img, t_vec2 center, int size);

#endif
