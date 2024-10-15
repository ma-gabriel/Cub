/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:41:44 by geymat            #+#    #+#             */
/*   Updated: 2024/10/15 17:53:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKS_H
# define MAP_CHECKS_H

# include "struct.h"

bool	check_only_map(char **file);
int		struct_init(t_mlx_p mlx, t_window_p win,
			t_thegame *game, char *file_name);
bool	check_arg(int argc, char *map);
char	**read_file(char *file);
bool	check_closed_map(char **file);

#endif
