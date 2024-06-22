/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:24 by geymat            #+#    #+#             */
/*   Updated: 2024/06/22 06:02:26 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_textures
{
	void			*no;
	void			*so;
	void			*we;
	void			*ew;
	unsigned char	f[3];
	unsigned char	c[3];
}		t_textures;

typedef struct s_game
{
	t_textures	textures;
	char		**map;
}	t_thegame;

#endif
