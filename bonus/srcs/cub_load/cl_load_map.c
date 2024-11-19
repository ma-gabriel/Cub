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

static int	get_map(char **file, char **cpy, t_parse *parse)
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

int	check_and_get_map(char **file, char **cpy, t_parse *parse, char check)
{
	if (check != 0b01111110 && check != 0b01111111)
	{
		ft_putstr_fd(ERR INFO_MISSING NL, 2);
		ft_strsfree(cpy);
		return (1);
	}
	return (get_map(file, cpy, parse));
}
