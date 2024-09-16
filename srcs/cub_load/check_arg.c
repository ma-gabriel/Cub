/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:58:59 by gcros             #+#    #+#             */
/*   Updated: 2024/09/13 15:01:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

bool	check_arg(int argc, char *map)
{
	int	fd;

	if (argc == 1)
		return (!write(2, ERR NEED_ARG NL, 36));
	if (argc > 2)
		return (!write(2, ERR ONLY_ONE_ARG NL, 33));
	if (ft_strlen(map) < 5 || ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
		return (!write(2, ERR WRONG_EXTENSION NL, 65));
	fd = open(map, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (!write(2, ERR ARG_DIRECTORY NL, 43));
	}
	return (true);
}
