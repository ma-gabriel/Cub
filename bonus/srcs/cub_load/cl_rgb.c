/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:14:27 by geymat            #+#    #+#             */
/*   Updated: 2024/11/04 03:14:31 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "defines.h"
#include "libft.h"
#include <stdbool.h>

static t_color	fill_rgb(char **temp)
{
	t_color	rgb;

	rgb.r = ft_atoi(temp[0]);
	rgb.g = ft_atoi(temp[1]);
	rgb.b = ft_atoi(temp[2]);
	rgb.a = 0;
	return (rgb);
}

static bool	wrong_rgb(void)
{
	ft_putstr_fd(ERR WRONG_RGB_VALUES NL, 2);
	return (false);
}

// Check que les valeurs soient >= 0 et <= 255. 
// Enlève les espaces en debut et fin de nombre
// Verifie que le nombre ne soit bien qu'un nombre
static bool	check_rgb(char **split)
{
	size_t	len;
	char	*temp;

	len = ft_strslen(split);
	if (len != 3)
		return (wrong_rgb());
	while (*split)
	{
		temp = ft_strtrim(*split, " \f\r\t\v");
		if (!temp)
		{
			ft_putstr_fd(ERR MALLOC_FAIL NL, 2);
			return (0);
		}
		free(*split);
		*split = temp;
		if (!ft_strisnumber(*split) || (unsigned long) ft_atol(*split) > 255)
			return (wrong_rgb());
		split++;
	}
	return (true);
}

//return 0 for error, 1 for working succesfully
//memory[2] is to check if we already have the colors
bool	fill_color(t_parse *parse, short id, char *line)
{
	char		**temp;
	static bool	memory[2] = {0, 0};

	if (memory[id - 5])
	{
		ft_putstr_fd(ERR DOUBLE_RGB NL, 2);
		return (false);
	}
	if (ft_strnstr(line, ",,", ft_strlen(line)))
		return (wrong_rgb());
	memory[id - 5] = true;
	temp = ft_split(line + 1, ',');
	if (!temp || !check_rgb(temp))
	{
		if (temp)
			ft_strsfree(temp);
		return (0);
	}
	if (id == 5)
		parse->textures.f = fill_rgb(temp);
	else if (id == 6)
		parse->textures.c = fill_rgb(temp);
	ft_strsfree(temp);
	return (1);
}
