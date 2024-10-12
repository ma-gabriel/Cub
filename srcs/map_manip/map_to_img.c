/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:11:30 by gcros             #+#    #+#             */
/*   Updated: 2024/10/11 22:43:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manip.h"
#include "draw.h"
#include "str.h"
#include "put.h"
#include "map_manip.h"

size_t	strs_len(char **strs);

t_image_p	map_to_image(t_mlx_p mlx, t_map_p map, int width, int height)
{
	t_image_p	img;

	img = mm_image_new(mlx, width, height);
	if (img == NULL)
		return (NULL);
	map_draw(map, &img->img);
	return (img);
}

t_color	cell_get_color(t_cell_type type)
{
	static t_color	tmp[CT_LENGHT] = {
	[ct_void] = {.value = 0x00646464},
	[ct_wall] = {.value = 0x00000000},
	[ct_door_close] = {.value = 0x00C86464},
	[ct_door_open] = {.value = 0x00C8C8C8},
	[ct_floor] = {.value = ~0xFF000000},
	[ct_unknow] = {.value = 0x00FFC40F},
	[ct_oob] = {.value = 0x000000FF},
	};

	if (type > CT_LENGHT)
		type = ct_unknow;
	return (tmp[type]);
}

void	map_draw(t_map_p map, t_img_p img)
{
	int				i;
	int				j;
	t_color			c;
	const t_vec2	ratio = (t_vec2){img->width / (double)map->width,
		img->height / (double)map->height};

	mm_img_set_bg(img, (t_color){.value = 0xFF080808});
	i = map->height;
	while (i--)
	{
		j = map->width;
		while (j--)
		{
			c = cell_get_color(map->data[i * map->width + j]);
			draw_rect(img, (t_vec2){(j * ratio.x),
				(i * ratio.y)},
				(t_vec2){ratio.x + 1., ratio.y + 1.}, c);
		}
	}
}
