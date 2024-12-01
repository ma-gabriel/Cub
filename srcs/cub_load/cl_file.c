/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:01:53 by geymat            #+#    #+#             */
/*   Updated: 2024/11/13 20:17:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "struct.h"
#include "defines.h"
#include "libft.h"
#include "map_checks.h"
#include <stdio.h>
#include "mlx.h"
#include "mlx_manip.h"

static bool	is_file_empty(char **file);

// read the file line by line
// the buffer contain all that is read
//   and if the buffer has the file correctly read
//   file will point to buffer
// if a malloc suddently fail, *file is all free
//   meaning the previous buffer
static bool	read_fd(int fd, char ***file)
{
	char	**buffer;
	size_t	line;

	line = 0;
	*file = NULL;
	while (!line || (*file)[line - 1])
	{
		buffer = malloc((line + 1) * sizeof(char *));
		if (!buffer)
		{
			if (*file)
				ft_strsfree(*file);
			return ((bool)(*file = NULL));
		}
		ft_memcpy(buffer, *file, line * sizeof(char *));
		buffer[line] = get_next_line(fd);
		if (buffer[line] && buffer[line][ft_strlen(buffer[line]) - 1] == '\n')
			buffer[line][ft_strlen(buffer[line]) - 1] = 0;
		if (line)
			free(*file);
		*file = buffer;
		line++;
	}
	return (true);
}

char	**read_file(char *file)
{
	int		fd;
	char	**res;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(ERR OPEN_FAIL NL, 2);
		return (NULL);
	}
	res = (void *) 1;
	if (!read_fd(fd, &res))
	{
		ft_putstr_fd(ERR MALLOC_FAIL NL, 2);
		close(fd);
		return (NULL);
	}
	if (is_file_empty(res))
	{
		ft_putstr_fd(ERR "empty file, or could open but not read" NL, 2);
		ft_strsfree(res);
		res = NULL;
	}
	close(fd);
	return (res);
}

static bool	is_file_empty(char **file)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (file[j])
	{
		i = 0;
		while (file[j][i])
		{
			if (file[j][i] != ' ' && !(file[j][i] >= 9 && file[j][i] <= 13))
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}