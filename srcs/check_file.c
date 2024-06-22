/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:47:00 by geymat            #+#    #+#             */
/*   Updated: 2024/06/21 23:47:02 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
#include "defines.h"
#include "struct.h"

size_t	strs_len(char **strs);

bool	check_only_map(char **file)
{
	bool	start;
	char	c;
	size_t	i;

	start = false;
	while (*file)
	{
		i = 0;
		while ((*file)[i])
		{
			c = (*file)[i];
			if ((c == 'N' || c == 'E' || c == 'W' || c == 'S') && !start)
				start = true;
			else if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
				return (!write(2, ERR MULTIPLE_START NL, 50));
			else if (c != ' ' && !(c >= 9 && c <= 13) && c != '1' && c != '0')
				return (!write(2, ERR WRONG_CHAR NL, 84));
			i++;
		}
		file++;
	}
	return (true);
}

static bool	exterior(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

bool	check_closed_map(char **file)
{
	char	c;
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			c = file[i][j];
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0')
			{
				if (!i || !j || j == ft_strlen(file[i]) || !(file[i + 1] && \
				j < ft_strlen(file[i + 1])) || !(file[i - 1] && \
				j < ft_strlen(file[i - 1])) || exterior(file[i - 1][j]) \
				|| exterior(file[i + 1][j]) || exterior(file[i][j - 1]) \
				|| exterior(file[i][j + 1]))
					return (!write(2, ERR UNCLOSED_MAP NL, 29));
			}
			j++;
		}
		i++;
	}
	return (true);
}

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
