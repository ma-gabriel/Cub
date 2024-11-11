/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:22:34 by geymat            #+#    #+#             */
/*   Updated: 2024/11/04 03:22:37 by geymat           ###   ########.fr       */
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

// if exec go 0, it means that
// something went wrong, like bad malloc or bad input
static int	struct_fill(t_parse *parse, char *file_name)
{
	void *const	save = read_file(file_name);
	char		**file;
	short		hub;
	bool		exec;
	char		check;

	if (!save)
		return (1);
	file = save;
	check = 0;
	exec = 1;
	while (*file && exec)
	{
		hub = redirect(*file);
		if (hub == -1)
			return (check_and_get_map(file, save, parse, check));
		check |= 1 << hub;
		if (hub >= 1 && hub <= 4)
			exec = fill_texture(parse, hub, *file);
		if (hub >= 5)
			exec = fill_color(parse, hub, *file);
		file++;
	}
	ft_strsfree(save);
	return (1);
}

static bool	fill_texture(t_parse *parse, short id, char *line)
{
	char		error_message[47];
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
		return ((!write(2, error_message, 47)));
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

int	struct_init(t_mlx_p mlx, t_window_p win, t_parse *parse, char *file_name)
{
	int	res;

	parse->window.mlx_ptr = mlx;
	parse->window.win_ptr = win;
	res = struct_fill(parse, file_name);
	if (res)
		destroy_image_parsing(parse->textures, mlx);
	return (res);
}
