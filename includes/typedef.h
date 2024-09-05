/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:06:04 by gcros             #+#    #+#             */
/*   Updated: 2024/09/04 22:06:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

/*                                     typedef                                */

typedef struct s_kb_event	t_kb_event;
typedef t_kb_event			*t_kb_event_p;

typedef struct s_window		t_window;
typedef t_window			*t_window_p;

typedef struct s_image		t_image;
typedef t_image				*t_image_p;

typedef struct s_img		t_img;
typedef t_img				*t_img_p;

typedef void*				t_mlx_p;
typedef void*				t_win_p;

typedef struct s_color		t_color;

typedef struct s_loop_param	t_loop_param;

#endif