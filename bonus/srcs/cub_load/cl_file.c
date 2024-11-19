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

static int	is_file_empty(char **file);

int	read_fd(int fd, char ***file)
{
	char	**temp;
	size_t	i;

	i = 0;
	*file = NULL;
	while (!i || (*file)[i - 1])
	{
		temp = malloc((i + 1) * sizeof(char *));
		if (!temp)
		{
			if (*file)
				ft_strsfree(*file);
			return (!!(*file = NULL));
		}
		ft_memcpy(temp, *file, i * sizeof(char *));
		temp[i] = get_next_line(fd);
		if (temp[i] && temp[i][ft_strlen(temp[i]) - 1] == '\n')
			temp[i][ft_strlen(temp[i]) - 1] = 0;
		if (i)
			free(*file);
		*file = temp;
		i++;
	}
	return (1);
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
		ft_putstr_fd(ERR "empty file" NL, 2);
		ft_strsfree(res);
		res = NULL;
	}
	close(fd);
	return (res);
}

static int	is_file_empty(char **file)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (file[j])
	{
		i = 0;
		while (file[j][i])
		{
			if (!(file[j][i] == ' ' || (file[j][i] >= 9 && file[j][i] <= 13)))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
