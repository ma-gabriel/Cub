/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:08:36 by gcros             #+#    #+#             */
/*   Updated: 2024/10/11 16:45:32 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOUND_H
# define FT_SOUND_H

# include <sys/types.h>

# define K_SOUND 1

typedef struct s_snd
{
	u_int64_t	_1;
	u_int64_t	_2;
	u_int16_t	code;
	u_int16_t	type;
	int32_t		value;
}	t_snd;

void	ft_sound(int tone);

#endif