/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:30:07 by gcros             #+#    #+#             */
/*   Updated: 2024/09/02 15:57:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANIP_H
# define MLX_MANIP_H

/*                                     typdef                                 */
typedef struct s_window		t_window;
typedef t_window			*t_window_p;

typedef struct s_image		t_image;
typedef t_image				*t_image_p;

typedef struct s_img		t_img;
typedef t_img				*t_img_p;

typedef void*				t_mlx_p;
typedef void*				t_win_p;

typedef struct s_color		t_color;

typedef struct s_loop_param	t_loop_param;

/*                                     global utils                           */

struct s_loop_param
{
	t_mlx_p		mlx;
	t_window_p	win;
	t_image_p	img;
};

int			loop(t_loop_param *param);

/*                                     color manip                            */

struct s_color
{
	union
	{
		//	0XAARRGGBB
		int	value;
		struct
		{
			unsigned char	b;
			unsigned char	g;
			unsigned char	r;
			unsigned char	a;
		};
	};
};

t_color		mm_get_color(int a, int r, int g, int b);
void		mm_color_phex(t_color color);

/*                                     mlx manip                              */

t_mlx_p		mm_mlx_new(void);
void		mm_mlx_delete(t_mlx_p mlx);

/*                                     image manip                            */

struct s_img
{
	void	*img_ptr;
	t_color	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
};

t_img_p		mm_img_new(t_mlx_p mlx, int width, int height);
int			mm_img_init(t_img_p img_p, t_mlx_p mlx, int width, int height);
void		mm_img_putpixel(t_img_p img, int x, int y, t_color color);
void		mm_img_putpixel_s(t_img_p img, int x, int y, t_color color);
t_color		mm_img_getpixel(t_img_p img, int x, int y);
void		mm_img_clear(t_img_p img);
void		mm_img_set_bg(t_img_p img, t_color color);
void		mm_img_display(t_img_p img, t_window_p win, int x, int y);
void		mm_img_destroy(t_img_p img, t_mlx_p mlx);
void		mm_img_delete(t_img_p img, t_mlx_p mlx);

struct s_image
{
	t_img	img;
	t_mlx_p	mlx_ptr;
};

t_image_p	mm_image_new(t_mlx_p mlx, int width, int height);
int			mm_image_init(t_image_p img, t_mlx_p mlx, int width, int height);
void		mm_image_destroy(t_image_p img);
void		mm_image_delete(t_image_p img);

/*                                     window manip                           */

struct s_window
{
	t_win_p	win_ptr;
	t_mlx_p	mlx_ptr;
};

t_window_p	mm_window_new(t_mlx_p mlx, int width, int height, char *name);
void		mm_window_delete(t_window_p win);

#endif