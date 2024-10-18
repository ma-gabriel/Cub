/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:01:53 by geymat            #+#    #+#             */
/*   Updated: 2024/10/18 16:49:18 by gcros            ###   ########.fr       */
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

// static void	destroy_one_texture(t_mlx_p	mlx, t_img *texture)
// {
// 	if (!texture->img_ptr)
// 		return ;
// 	mlx_destroy_image(mlx, texture->img_ptr);
// 	ft_bzero(texture, sizeof(t_img));
// }

// void	destroy_all_textures(t_parse *parse)
// {
// 	const t_mlx_p	mlx = parse->window.mlx_ptr;
// 	int				i;

// 	destroy_one_texture(mlx, &(parse->textures.no));
// 	destroy_one_texture(mlx, &(parse->textures.so));
// 	destroy_one_texture(mlx, &(parse->textures.we));
// 	destroy_one_texture(mlx, &(parse->textures.ea));
// 	i = 0;
// 	while (i < SPRITE_IMGS)
// 	{
// 		destroy_one_texture(mlx, &(parse->textures.sprite.images[i]));
// 		i++;
// 	}
// }

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
	if (!read_fd(fd, &res))
	{
		write(2, ERR MALLOC_FAIL NL, 23);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (res);
}

void	strs_free(char **strs)
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

int	get_map(char **file, char **cpy, t_parse *parse)
{
	size_t	i;

	// if (!check_only_map(file) || !check_closed_map(file))
	// {
	// 	strs_free(cpy);
	// 	return (1);
	// }
	parse->map = malloc(sizeof(char *) * (strs_len(file) + 1));
	if (!(parse->map))
	{
		write(2, ERR MALLOC_FAIL NL, 23);
		strs_free(cpy);
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
	strs_free(cpy);
	return (0);
}

int	check_and_get_map(char **file, char **cpy, t_parse *parse, char check)
{
	if (check != 0b01111110 && check != 0b01111111)
	{
		write(2, ERR INFO_MISSING NL, 85);
		strs_free(cpy);
		return (1);
	}
	return (get_map(file, cpy, parse));
}

t_color	fill_rgb(char **temp)
{
	t_color	rgb;

	rgb.r = ft_atoi(temp[0]);
	rgb.g = ft_atoi(temp[1]);
	rgb.b = ft_atoi(temp[2]);
	rgb.a = 0;
	return (rgb);
}

// Check que les valeurs soient >= 0 et <= 255. 
// Enlève les espaces en debut et fin de nombre
// Verifie que le nombre ne soit bien qu'un nombre
bool	check_rgb(char **split)
{
	size_t	len;
	char	*temp;

	len = strs_len(split);
	if (len != 3)
		return (!write (2, ERR WRONG_RGB_VALUES NL, 34));
	while (*split)
	{
		temp = ft_strtrim(*split, " \f\r\t\v");
		if (!temp)
			return (!write (2, ERR MALLOC_FAIL NL, 23));
		free(*split);
		*split = temp;
		if (!ft_strisnumber(*split) || (unsigned long) ft_atol(*split) > 255)
			return (!write (2, ERR WRONG_RGB_VALUES NL, 34));
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
		return (!write(2, ERR DOUBLE_RGB NL, 58));
	if (ft_strnstr(line, ",,", ft_strlen(line)))
		return (!write (2, ERR WRONG_RGB_VALUES NL, 34));
	memory[id - 5] = true;
	temp = ft_split(line + 1, ',');
	if (temp == NULL)
		return (0);
	if (!check_rgb(temp))
	{
		strs_free(temp);
		return (0);
	}
	if (id == 5)
		parse->textures.f = fill_rgb(temp);
	else if (id == 6)
		parse->textures.c = fill_rgb(temp);
	strs_free(temp);
	return (1);
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

bool	fill_texture(t_parse *parse, short id, char *line)
{
	char		error_message[47];
	t_img_p		*aimed;

	ft_bzero(error_message, sizeof(char) * 47);
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
		return (!write(2, ERR MLX_FAILED NL, 44));
	return (1);
}

// if exec go 0, it means that
// something went wrong, like bad malloc or bad input
int	struct_fill(t_parse *parse, char *file_name)
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
	strs_free(save);
	return (1);
}

bool	add_sprite(t_parse *parse)
{
	if (mm_file_to_img_init( &(parse->textures.sprite.images[0]), parse->window.mlx_ptr, "./textures/sprite1.xpm"))
		return (1);
	if (mm_file_to_img_init(&(parse->textures.sprite.images[1]), parse->window.mlx_ptr, "./textures/sprite2.xpm"))
		return (1);
	return (0);
	
}

int	struct_init(t_mlx_p mlx, t_window_p win, t_parse *parse, char *file_name)
{
	int	res;

	parse->window.mlx_ptr = mlx;
	parse->window.win_ptr = win;
	res = struct_fill(parse, file_name);
	// if (res == 0)
	// 	res = add_sprite(parse);
	if (res == 0)
		return (0);
	return (res);
}
