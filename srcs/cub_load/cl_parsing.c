/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:22:34 by geymat            #+#    #+#             */
/*   Updated: 2024/11/25 15:53:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "defines.h"
#include "map_checks.h"
#include "libft.h"
#include <stdbool.h>

static bool	fill_texture(t_parse *parse, short id, char *line);

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

// bitmap is used to know if every of the 6 inputs are in the map
// hub is used to redirect what the line in the file is
static int	parsing_fill(t_parse *parse, char *file_name)
{
	void *const	save = read_file(file_name);
	char		bitmask;
	char		**file;
	short		hub;

	if (!save)
		return (1);
	file = save;
	bitmask = 0;
	while (*file && hub != -1)
	{
		hub = redirect(*file);
		if (hub == -1 && has_all_infos(bitmask))
			return (get_map(file, save, parse));
		bitmask |= 1 << hub;
		if (hub >= 1 && hub <= 4 && !fill_texture(parse, hub, *file))
			break ;
		if (hub >= 5 && !fill_color(parse, hub, *file))
			break ;
		file++;
	}
	ft_strsfree(save);
	return (1);
}

static bool	fill_texture(t_parse *parse, short id, char *line)
{
	char		error_message[46];
	t_img_p		*aimed;

	ft_strcpy(error_message, "Error\nThe texture XX is asked at least twice\n");
	ft_strncpy(error_message + 18, line, 2);
	line += 2;
	if (id == 1)
		aimed = &(parse->textures.no);
	else if (id == 2)
		aimed = &(parse->textures.so);
	else if (id == 3)
		aimed = &(parse->textures.we);
	else if (id == 4)
		aimed = &(parse->textures.ea);
	while (*line == ' ' || (*line >= 9 && *line <= 13))
		line++;
	if (*aimed)
		return ((!write(2, error_message, 45)));
	*aimed = mm_file_to_img_new(parse->window.mlx_ptr, line);
	if (*aimed == NULL)
		ft_putstr_fd(ERR MLX_FAILED NL, 2);
	return (!!(*aimed));
}

static void	destroy_image_parsing(t_textures textures, t_mlx_p mlx)
{
	if (textures.ea)
		mm_img_delete(textures.ea, mlx);
	if (textures.no)
		mm_img_delete(textures.no, mlx);
	if (textures.so)
		mm_img_delete(textures.so, mlx);
	if (textures.we)
		mm_img_delete(textures.we, mlx);
}

int	parsing_init(t_mlx_p mlx, t_window_p win, t_parse *parse, char *file_name)
{
	int	res;

	parse->window.mlx_ptr = mlx;
	parse->window.win_ptr = win;
	res = parsing_fill(parse, file_name);
	if (res)
		destroy_image_parsing(parse->textures, mlx);
	return (res);
}
