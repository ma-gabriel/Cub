/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 00:41:44 by geymat            #+#    #+#             */
/*   Updated: 2024/11/19 16:05:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKS_H
# define MAP_CHECKS_H

# include "struct.h"
# include <stdbool.h>

int		struct_init(t_mlx_p mlx, t_window_p win,
			t_parse *parse, char *file_name);
int		check_arg(int argc, char *map);
char	**read_file(char *file);
bool	fill_color(t_parse *parse, short id, char *line);
int		check_and_get_map(char **file, char **cpy, t_parse *parse, char check);

#endif
