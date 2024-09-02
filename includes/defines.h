/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:14 by geymat            #+#    #+#             */
/*   Updated: 2024/06/22 06:02:15 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifndef O_DIRECTORY
#  define O_DIRECTORY	020000
# endif
# define ERR "Error\n"
# define NL "\n"
# define NEED_ARG "We need a map as an argument"
# define ONLY_ONE_ARG "We only take one argument"
# define WRONG_EXTENSION "The map doesn't have a \
valid name (extension must be .cub)"
# define ARG_DIRECTORY "Did you really give a directory ???"
# define OPEN_FAIL "The file didn't open"
# define MALLOC_FAIL "A malloc failed"
# define MULTIPLE_START "Multiple starts have been found in the map"
# define WRONG_CHAR "The file must be textures and colors (at the start of their line), \
then the map with only authorised characters"
# define UNCLOSED_MAP "The map is not closed"
# define WRONG_RGB_VALUES "The rgb values are invalid"
# define MLX_FAILED "An mlx function failed"
# define INFO_MISSING "There are some infos missing in the cub file, put the 4 textures and 2 colors"

#endif
