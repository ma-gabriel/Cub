/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:14 by geymat            #+#    #+#             */
/*   Updated: 2024/11/20 14:22:31 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define ERR "Error\n"
# define NL "\n"
# define NEED_ARG "We need a map as an argument"
# define ONLY_ONE_ARG "We only take one argument"
# define WRONG_EXTENSION "The map doesn't have a valid extension (must be .cub)"
# define ARG_DIRECTORY "Did you really give a directory ???"
# define OPEN_FAIL "The file didn't open"
# define MALLOC_FAIL "A malloc failed"
# define MULTIPLE_START "Multiple starts have been found in the map"
# define NO_START "You forgot the start in the map"
# define WRONG_RGB_VALUES "The rgb values are invalid"
# define MLX_FAILED "MLX function failed to open XPM file"
# define INFO_MISSING "Infos are missing in the .cub (need 4 xpm and 2 rgb)"
# define DOUBLE_RGB "Floor and Ceiling colors should be asked once each"
# define UNRECOGNIZED "Unreconized char"

/*                                     sprite define                          */

# ifndef SPRITE_IMGS
#  define SPRITE_IMGS 6
# endif

# if SPRITE_IMGS <= 0
#  undef SPRITE_IMGS
#  define SPRITE_IMGS 1
# endif

# define SPRITE_DIR "assets/break/"
# define SPRITE_PREFIX "breakable_wall"
# define SPRITE_POSTFIX ".xpm"

/*                                     ui define                              */

# define THICKNESS_RAYS 1
# define WIN_WIDTH 1000
# define WIN_HEIGHT 700
# define WIN_NAME "cub3D"
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200

#endif
