/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:24 by geymat            #+#    #+#             */
/*   Updated: 2024/09/02 18:11:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "mlx_manip.h"

typedef struct s_image_gab
{
	void		*image;
	int			width;
	int			height;
}		t_image_gab;

typedef struct s_textures
{
	t_image_gab		no;
	t_image_gab		so;
	t_image_gab		we;
	t_image_gab		ea;
	t_color			f;
	t_color			c;
}		t_textures;

typedef struct s_game
{
	t_textures	textures;
	char		**map;
	t_window	window;
}	t_thegame;

#endif
