/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:11:30 by gcros             #+#    #+#             */
/*   Updated: 2024/09/04 21:33:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "draw.h"
#include "str.h"
#include "put.h"

void	map_fill(t_img_p img, char **map);
size_t	strs_len(char **strs);

t_image_p	map_to_image(t_mlx_p mlx, char **map, int width, int height)
{
	t_image_p	img;

	img = mm_image_new(mlx, width, height);
	if (img == NULL)
		return (NULL);
	map_fill(&img->img, map);
	return (img);
}

static t_color	to_c(char c)
{
	if (c == ' ')
		return ((t_color){.value = 0x0});
	else if (c == '1')
		return ((t_color){.value = 0x0});
	else if (c == '0')
		return ((t_color){.value = 0x00FFFFFF});
	return ((t_color){.value = 0x00808080});
}

void	map_fill(t_img_p img, char **map)
{
	const int	x = ft_strlen(map[0]);
	const int	y = strs_len(map);
	int			i;
	int			j;
	t_color		c;

	mm_img_set_bg(img, (t_color){.value = 0x00080808});
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			c = to_c(map[j][i]);
			draw_rect(img, (t_vec2){i * (img->width / (double)x),
				j * (img->height / (double)y)},
				(t_vec2){img->width / (double)x, img->height / (double)y}, c);
			j++;
		}
		i++;
	}
}
