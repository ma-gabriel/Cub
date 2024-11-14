/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:44:50 by gcros             #+#    #+#             */
/*   Updated: 2024/10/28 21:15:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "texture_manip.h"
#include "str.h"
#include "libft.h"

static t_img_p	load_one(unsigned int num, t_mlx_p mlx);
static int		load_all(t_img_descriptor_p imgd, t_mlx_p mlx);
static void		get_midfix(char buf[11], unsigned int num);

int	cl_load_sprite(t_img_descriptor_p imgd, t_mlx_p mlx)
{
	if (load_all(imgd, mlx))
		return (1);
	return (0);
}

static int	load_all(t_img_descriptor_p imgd, t_mlx_p mlx)
{
	unsigned int	i;
	t_img_p			img;

	i = 0;
	while (i < SPRITE_IMGS)
	{
		img = load_one(i, mlx);
		if (img == NULL)
			return (1);
		imgd->imgs[id_sprite_start + i] = img;
		i++;
	}
	return (0);
}

static t_img_p	load_one(unsigned int num, t_mlx_p mlx)
{
	char	midfix[11];
	char	*name;
	t_img_p	img;

	get_midfix(midfix, num);
	name = ft_strsjoin((char *[]){SPRITE_DIR SPRITE_PREFIX,
			midfix, SPRITE_POSTFIX, NULL});
	if (name == NULL)
	{
		ft_putstr_fd(ERR MALLOC_FAIL NL, 2);
		return (NULL);
	}
	img = mm_file_to_img_new(mlx, name);
	free(name);
	if (!img)
		ft_putstr_fd(ERR MLX_FAILED NL, 2);
	return (img);
}

static void	get_midfix(char buf[11], unsigned int num)
{
	int	cp;
	int	digit;

	cp = num;
	digit = 1;
	while (cp / 10 > 0)
	{
		digit++;
		cp /= 10;
	}
	buf[digit] = '\0';
	buf[--digit] = '0' + (num % 10);
	while (num / 10)
	{
		num /= 10;
		buf[--digit] = '0' + (num % 10);
	}
}
