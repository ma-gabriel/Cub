/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:01:53 by geymat            #+#    #+#             */
/*   Updated: 2024/06/22 06:01:56 by geymat           ###   ########.fr       */
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

/*

read_fd va surement devoir etre a jeter car ne conserve pas les \n 
donc pour la map, il y aura de la perte dans un cas tel que:

11111
10001
11111

11111
10001
11111

J'attends ton get_next_line gcros pour ca. Ou du moins ta libft

*/
int	read_fd(int fd, char ***file)
{
	char	*line;
	char	*temp;
	char	buffer[101];
	ssize_t	bytes;

	bytes = 1;
	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (!!(*file = NULL));
	while (bytes && line)
	{
		bytes = read(fd, buffer, 100);
		if (bytes == -1)
			break ;
		buffer[bytes] = 0;
		temp = ft_strjoin(line, buffer);
		free(line);
		if (!temp)
			return (!!(*file = NULL));
		line = temp;
	}
	if (!bytes)
		*file = ft_split(line, '\n');
	free(line);
	return (bytes == -1);
}

char	**read_file(char *file)
{
	int		fd;
	char	**res;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, ERR OPEN_FAIL NL, 28);
		return (NULL);
	}
	res = (void *) 1;
	if (read_fd(fd, &res) || !res)
	{
		if (res)
			write(2, ERR READ_FAIL NL, 33);
		else
			write(2, ERR MALLOC_FAIL NL, 23);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (res);
}

static short	redirect(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	if (!ft_strncmp(line, "SO ", 3))
		return (2);
	if (!ft_strncmp(line, "WE ", 3))
		return (3);
	if (!ft_strncmp(line, "EA ", 3))
		return (4);
	if (!ft_strncmp(line, "F ", 2))
		return (5);
	if (!ft_strncmp(line, "C ", 2))
		return (6);
	while (*line)
	{
		if (!(*line == ' ' || (*line >= 9 && *line <= 13)))
			return (-1);
		line++;
	}
	return (0);
}

static void	strs_free(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

size_t	strs_len(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	get_map(char **file, char **cpy, t_thegame *game)
{
	size_t	i;

	if (!check_only_map(file)) // add to check if the map is valid;
	{
		strs_free(cpy);
		return (1);
	}
	game->map = malloc((sizeof(char *) + 1) * strs_len(file));
	if (!(game->map))
	{
		write(2, ERR MALLOC_FAIL NL, 23);
		strs_free(cpy);
		return (1);
	}
	i = 0;
	while (file[i])
	{
		game->map[i] = file[i];
		file[i] = NULL;
		i++;
	}
	game->map[i] = NULL;
	strs_free(cpy);
	return (0);
}

int	struct_init(t_thegame *game, char *file_name)
{
	char		**file;
	void		*cpy;
	short		hub;

	file = read_file(file_name);
	cpy = file;
	if (!file)
		return (1);
	while (*file)
	{
		hub = redirect(*file);
		if (hub == -1)
			return (get_map(file, cpy, game));
		if (hub >= 1 && hub <= 4)
			printf("found a path at line : %s\n", *file);
		if (hub >= 5)
			printf("rgb color at line: %s\n", *file);
		file++;
	}
	strs_free(cpy);
	return (1);
}
