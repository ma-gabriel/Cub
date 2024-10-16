/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:41:44 by geymat            #+#    #+#             */
/*   Updated: 2024/10/16 22:44:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKS_H
# define MAP_CHECKS_H

# include "struct.h"

int		check_only_map(char **file);
int		struct_init(t_mlx_p mlx, t_window_p win,
			t_parse *parse, char *file_name);
int		check_arg(int argc, char *map);
char	**read_file(char *file);
int		check_closed_map(char **file);

#endif
