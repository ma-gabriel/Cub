/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:37:55 by gcros             #+#    #+#             */
/*   Updated: 2024/10/19 20:06:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_PI 3.14159
#define M_PI_2 1.57079
#include "mlx_manip.h"
#include "struct.h"
#include "raycast_manip.h"
#include "texture_manip.h"
#include "math.h"
#include "libft.h"
#include "map_manip.h"

static t_vec2	h(t_map_p map, t_vec2 start, double angle, t_cell_flag flag);
static t_vec2	v(t_map_p map, t_vec2 start, double angle, t_cell_flag flag);
static t_vec2	a(t_map_p map, t_cell_flag flag, t_vec2 dp, t_vec2 pos);

t_raycast	rc_throw(t_map_p map, t_vec2 start, double angle, t_cell_flag flag)
{
	t_raycast	rc;
	t_vec2		pos;
	t_vec2		tmp;

	angle = ft_norm_angle(angle);
	pos = v(map, start, angle, flag);
	tmp = h(map, start, angle, flag);
	if (hypot(pos.x, pos.y) < hypot(tmp.x, tmp.y))
	{
		pos = tmp;
		rc.dist = cos(angle);
		rc.face = 2 + (angle > M_PI);
		rc.offset = ft_get_real(pos.x);
	}
	else
	{
		rc.dist = sin(angle);
		rc.face = (angle > M_PI_2 && angle < M_PI_2 * 3.);
		rc.offset = ft_get_real(pos.y);
	}
	rc.angle = angle;
	rc.dist *= hypot(pos.x, pos.y);
	rc.pos = pos;
	return (rc);
}

static t_vec2	v(t_map_p map, t_vec2 start, double angle, t_cell_flag flag)
{
	const double	ntan = -tan(angle);
	t_vec2			dp;
	t_vec2			pos;

	if (angle > M_PI_2 && angle < M_PI_2 * 3.)
	{
		pos.x = floor(start.x);
		pos.y = ft_get_real(start.x) * ntan + start.y;
		dp = (t_vec2){.x = -1., .y = -ntan};
	}
	else if (angle < M_PI_2 || angle > M_PI_2 * 3.)
	{
		pos.x = floor(start.x) + 1.;
		pos.y = (ft_get_real(start.x) - 1.) * ntan + start.y;
		dp = (t_vec2){.x = 1., .y = -ntan};
	}
	else
	{
		pos = start;
		dp = (t_vec2){.x = 1, .y = 0};
	}
	return (a(map, flag, dp, pos));
}

static t_vec2	h(t_map_p map, t_vec2 start, double angle, t_cell_flag flag)
{
	const double	atan = -1. / tan(angle);
	t_vec2			dp;
	t_vec2			pos;

	if (angle > M_PI && angle < M_PI * 2.)
	{
		pos.y = floor(start.y);
		pos.x = ft_get_real(start.y) * atan + start.x;
		dp = (t_vec2){.y = -1., .x = -atan};
	}
	else if (angle < M_PI && angle > 0)
	{
		pos.y = floor(start.y) + 1.;
		pos.x = (ft_get_real(start.y) - 1.) * atan + start.x;
		dp = (t_vec2){.y = 1., .x = -atan};
	}
	else
	{
		pos = start;
		dp = (t_vec2){.x = 0, .y = 1};
	}
	return (a(map, flag, dp, pos));
}

static t_vec2	a(t_map_p map, t_cell_flag flag, t_vec2 dp, t_vec2 pos)
{
	size_t		count;
	t_cell_type	ct;

	count = 10000;
	while (count--)
	{
		ct = map_get_cell_s(map, floorl(pos.x), floorl(pos.y));
		if (map_cell_setting(ct, flag.flags) != 0)
			break ;
		pos.x += dp.x;
		pos.y += dp.y;
	}
	return (pos);
}
