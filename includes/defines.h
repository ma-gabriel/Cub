/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:02:14 by geymat            #+#    #+#             */
/*   Updated: 2024/11/19 16:11:01 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define ERR "Error\n"
# define NL "\n"
# define NEED_ARG "We need a map as an argument"
# define ONLY_ONE_ARG "We only take one argument"
# define WRONG_EXTENSION "The map doesn't have a valid extension (must be .cub)"
# define OPEN_FAIL "The file didn't open"
# define MALLOC_FAIL "A malloc failed"
# define MULTIPLE_START "Multiple starts have been found in the map"
# define NO_START "You forgot the start in the map"
# define WRONG_RGB_VALUES "The rgb values are invalid"
# define MLX_FAILED "MLX function failed to open XPM file"
# define DOUBLE_RGB "Floor and Ceiling colors should be asked once each"
# define UNRECOGNIZED "Unreconized char"

/*                                     ui define                              */

# define THICKNESS_RAYS 1
# define WIN_WIDTH 900
# define WIN_HEIGHT 500
# define WIN_NAME "cub3D"

#endif
