/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:55:45 by gcros             #+#    #+#             */
/*   Updated: 2024/01/23 14:14:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_cleanbuf(char *buf)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && buf[i] != EOL && buf[i] != EOS)
		i++;
	ft_strncpy(buf, buf + i + (buf[i] == EOL), BUFFER_SIZE - i);
	buf[BUFFER_SIZE - i] = EOS;
}

int	ft_linetostr(char **dest, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;	

	i = 0;
	j = 0;
	if (*dest)
		j = ft_strlen(*dest);
	while (i < (BUFFER_SIZE + 1) && buf[i] != EOL && buf[i] != EOS)
		i++;
	str = malloc(j + i + (buf[i] == EOL) + 1);
	if (!str)
	{
		free(*dest);
		*dest = NULL;
		return (-1);
	}
	ft_memcpy(str, *dest, j);
	ft_memcpy(str + j, buf, (buf[i] == EOL) + i);
	str[i + j + (buf[i] == EOL)] = EOS;
	free(*dest);
	*dest = str;
	return (buf[i] == EOL);
}

char	*get_next_line(int fd)
{
	static char	buf[FD_SIZE][BUFFER_SIZE + 1];
	char		*str;
	ssize_t		check;

	check = 0;
	str = NULL;
	while (check == 0 && fd != -1 && fd < FD_SIZE)
	{
		ft_cleanbuf(buf[fd]);
		if (buf[fd][0] == EOS)
		{
			check = read(fd, buf[fd], BUFFER_SIZE);
			if (check == 0)
				return (str);
			if (check == -1)
			{
				if (str != NULL)
					free(str);
				return (NULL);
			}
			buf[fd][check] = '\0';
		}
		check = ft_linetostr(&str, buf[fd]);
	}
	return (str);
}
