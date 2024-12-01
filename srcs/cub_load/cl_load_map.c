/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:25:44 by geymat            #+#    #+#             */
/*   Updated: 2024/11/04 03:25:49 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"
#include <stdbool.h>

int	get_map(char **file, char **cpy, t_parse *parse)
{
	size_t	i;

	parse->map = malloc(sizeof(char *) * (ft_strslen(file) + 1));
	if (!(parse->map))
	{
		ft_putstr_fd(ERR MALLOC_FAIL NL, 2);
		ft_strsfree(cpy);
		return (1);
	}
	i = 0;
	while (file[i])
	{
		parse->map[i] = file[i];
		file[i] = NULL;
		i++;
	}
	parse->map[i] = NULL;
	ft_strsfree(cpy);
	return (0);
}

bool	has_all_infos(char bitmask)
{
	const char *infos_missings[] = {"NO", "SO", "WE", "EA", "F", "C"};
	bool	res;
	short	i;

	res = true;
	i = 1;
	while (i < 7)
	{
		if ((bitmask & (1 << i)) == 0)
		{
			ft_putstr_fd(ERR "The info with the token ", 2);
			ft_putstr_fd((char *) infos_missings[i - 1], 2);
			ft_putstr_fd(" is missing." NL, 2);
			res = false;
		}
		i++;
	}
	return (res);
}
