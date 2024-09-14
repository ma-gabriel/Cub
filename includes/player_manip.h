/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manip.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:11:19 by gcros             #+#    #+#             */
/*   Updated: 2024/09/12 00:49:22 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MANIP_H
# define PLAYER_MANIP_H

# include "struct.h"

# define PLAYER_SIZE 0.1


typedef struct s_player	t_player;
typedef struct s_player	*t_player_p;

struct s_player
{
	double	angle;
	t_vec2	pos;
};

#endif