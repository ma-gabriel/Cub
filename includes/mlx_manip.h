/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:30:07 by gcros             #+#    #+#             */
/*   Updated: 2024/08/20 20:01:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANIP_H
# define MLX_MANIP_H

typedef struct s_window	t_window;
typedef t_window		*t_window_p;

/*	global utils	*/

typedef struct s_color
{
	union
	{
		struct
		{
			unsigned char	b;
			unsigned char	g;
			unsigned char	r;
			unsigned char	a;
		};
		int	value;
	};
}	t_color;

/*	mlx manip	*/

typedef void*			t_mlx_p;

t_mlx_p		mm_mlx_new(void);
void		mm_mlx_delete(t_mlx_p mlx);

/*	image manip	*/

typedef struct s_img
{
	void	*img_ptr;
	t_color	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
} t_img,	*t_img_p;

int			mm_img_init(t_img_p img_p, t_mlx_p mlx, int width, int height);
void		mm_img_putpixel(t_img_p img, int x, int y, t_color color);
void		mm_img_putpixel_s(t_img_p img, int x, int y, t_color color);
void		mm_img_clear(t_img_p img);
void		mm_img_set_bg(t_img_p img, t_color color);
void		mm_img_display(t_img_p img, t_window_p win, int x, int y);

typedef struct s_image
{
	t_img	img;
	t_mlx_p	mlx_ptr;
} t_image,	*t_image_p;

t_image_p	mm_image_new(t_mlx_p mlx, int width, int height);
void		mm_image_delete(t_image_p img);

/*	window manip	*/

typedef void*			t_win_p;

typedef struct s_window
{
	t_win_p	win_ptr;
	t_mlx_p	mlx_ptr;
}	t_window;

t_window_p	mm_window_new(t_mlx_p mlx, int width, int height, char *name);
void		mm_window_delete(t_window_p win);

#endif