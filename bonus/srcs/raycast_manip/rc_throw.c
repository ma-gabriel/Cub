/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:37:55 by gcros             #+#    #+#             */
/*   Updated: 2024/10/30 13:59:11 by gcros            ###   ########.fr       */
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

static t_vec2	horizontals_rays(t_map_p map, t_rc_sett rcs);
static t_vec2	vertical_rays(t_map_p map, t_rc_sett rcs);
static t_vec2	len_rays(t_map_p map, t_rc_sett rcs);

t_raycast	rc_throw(t_map_p map, t_rc_sett rcs)
{
	t_raycast	rc;
	t_vec2		pos;
	t_vec2		tmp;

	rcs.angle = ft_norm_angle(rcs.angle);
	pos = vertical_rays(map, rcs);
	tmp = horizontals_rays(map, rcs);
	if (hypot(pos.x - rcs.start.x, pos.y - rcs.start.y) \
		> hypot(tmp.x - rcs.start.x, tmp.y - rcs.start.y))
	{
		pos = tmp;
		rc.face = 2 + (rcs.angle > M_PI);
		rc.offset = ft_get_real(pos.x);
	}
	else
	{
		rc.face = (rcs.angle > M_PI_2 && rcs.angle < M_PI_2 * 3.);
		rc.offset = ft_get_real(pos.y);
	}
	(void)((rc.face == 1 || rc.face == 2) && (rc.offset = (1. - rc.offset)));
	rc.angle = rcs.angle;
	rc.dist = hypot(pos.x - rcs.start.x, pos.y - rcs.start.y);
	rc.pos = pos;
	return (rc);
}

static t_vec2	vertical_rays(t_map_p map, t_rc_sett rcs)
{
	const double	ntan = -tan(rcs.angle);
	t_vec2			dp;
	t_vec2			pos;

	if (rcs.angle > M_PI_2 && rcs.angle < M_PI_2 * 3.)
	{
		pos.x = floor(rcs.start.x) - 0.0001;
		pos.y = ft_get_real(rcs.start.x) * ntan + rcs.start.y;
		dp = (t_vec2){.x = -1., .y = ntan};
	}
	else if (rcs.angle < M_PI_2 || rcs.angle > M_PI_2 * 3.)
	{
		pos.x = floor(rcs.start.x) + 1.;
		pos.y = (ft_get_real(rcs.start.x) - 1.) * ntan + rcs.start.y;
		dp = (t_vec2){.x = 1., .y = -ntan};
	}
	else
	{
		pos = rcs.start;
		pos.y += ft_get_real(rcs.start.x) * ntan;
		dp = (t_vec2){.x = 0, .y = (rcs.angle == M_PI_2) * 2 - 1};
	}
	rcs.start = pos;
	rcs.delta = dp;
	return (len_rays(map, rcs));
}

static t_vec2	horizontals_rays(t_map_p map, t_rc_sett rcs)
{
	const double	atan = -1. / tan(rcs.angle);
	t_vec2			dp;
	t_vec2			pos;

	if (rcs.angle > M_PI && rcs.angle < M_PI * 2.)
	{
		pos.y = floor(rcs.start.y) - 0.0001;
		pos.x = ft_get_real(rcs.start.y) * atan + rcs.start.x;
		dp = (t_vec2){.y = -1., .x = atan};
	}
	else if (rcs.angle < M_PI && rcs.angle > 0.)
	{
		pos.y = floor(rcs.start.y) + 1.;
		pos.x = (ft_get_real(rcs.start.y) - 1.) * atan + rcs.start.x;
		dp = (t_vec2){.y = 1., .x = -atan};
	}
	else
	{
		pos = rcs.start;
		pos.x += ft_get_real(rcs.start.y) * atan;
		dp = (t_vec2){.x = (rcs.angle == 0.) * 2 - 1, .y = 0};
	}
	rcs.delta = dp;
	rcs.start = pos;
	return (len_rays(map, rcs));
}

static t_vec2	len_rays(t_map_p map, t_rc_sett rcs)
{
	size_t		count;
	t_vec2		pos;
	t_vec2		npos;
	t_cell_type	ct;

	count = rcs.max;
	pos = rcs.start;
	while (count--)
	{
		ct = map_get_cell_s(map, floor(pos.x), floor(pos.y));
		if (map_cell_setting(ct, rcs.attributes.value) != 0)
			return (pos);
		npos = pos;
		npos.x += rcs.delta.x;
		npos.y += rcs.delta.y;
		pos = npos;
	}
	return (pos);
}
