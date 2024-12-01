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

static bool	check_nb_arg(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd(ERR NEED_ARG NL, 2);
		return (false);
	}
	if (argc > 2)
	{
		ft_putstr_fd(ERR ONLY_ONE_ARG NL, 2);
		return (false);
	}
	return (true);
}

static bool	check_extension(char *map)
{
	if (ft_strlen(map) < 5)
	{
		ft_putstr_fd(ERR WRONG_EXTENSION NL, 2);
		return (false);
	}
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
	{
		ft_putstr_fd(ERR WRONG_EXTENSION NL, 2);
		return (false);
	}
	return (true);
}

bool	check_arg(int argc, char *map)
{
	if (!check_nb_arg(argc))
		return (false);
	if (!check_extension(map))
		return (false);
	return (true);
}