/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_90_180.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:52:54 by iobba             #+#    #+#             */
/*   Updated: 2023/04/29 14:58:34 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_hor_len(t_prog *gm, t_coor *coor, double h_ht_x, double h_ht_y)
{
	double	h_len;

	h_len = -1.0;
	if (h_ht_x == -3 * EACH)
	{
		h_ht_x = coor->h_hit_x;
		h_ht_y = coor->h_hit_y;
	}
	h_len = sqrt((gm->map.plyr.x * EACH - h_ht_x)
			* (gm->map.plyr.x * EACH - h_ht_x) + (gm->map.plyr.y
				* EACH - h_ht_y) * (gm->map.plyr.y * EACH - h_ht_y));
	coor->h_hit_x = h_ht_x;
	coor->h_hit_y = h_ht_y;
	return (h_len);
}

double	get_ver_len(t_prog *gm, t_coor *coor, double v_ht_x, double v_ht_y)
{
	double	v_len;

	v_len = -1.0;
	if (v_ht_x == -3 * EACH)
	{
		v_ht_x = coor->v_hit_x;
		v_ht_y = coor->v_hit_y;
	}
	v_len = sqrt((gm->map.plyr.x * EACH - v_ht_x) * (gm->map.plyr.x
				* EACH - v_ht_x) + (gm->map.plyr.y * EACH - v_ht_y)
			* (gm->map.plyr.y * EACH - v_ht_y));
	coor->v_hit_x = v_ht_x;
	coor->v_hit_y = v_ht_y;
	return (v_len);
}

double	from_90__180_ver(t_prog *game, double angle, t_coor *coor)
{
	double	v_hit_x;
	double	v_hit_y;
	double	v_x_step;
	double	v_y_step;

	v_hit_x = (int)game->map.plyr.x * EACH;
	v_hit_y = (game->map.plyr.y * EACH) - ((game->map.plyr.x * EACH)
			- v_hit_x) * -tan(angle);
	v_x_step = EACH;
	v_y_step = v_x_step * -tan(angle);
	while (EACH <= v_hit_y && v_hit_x >= EACH
		&& v_hit_x / EACH < ft_strlen(game->map.map[(int)v_hit_y / EACH])
		&& game->map.map[(int)v_hit_y / EACH][(int)v_hit_x / EACH - 1] != '1')
	{
		if (((int)(angle / M_PI * 180) == 135 && (angle / M_PI * 180) < 135.0001
			&& game->map.map[(int)(v_hit_y - 1) / EACH][(int)(v_hit_x - 1)
			/ EACH] == '1'))
		{
			v_hit_x = -3 * EACH;
			break ;
		}
		v_hit_x -= v_x_step;
		v_hit_y -= v_y_step;
	}
	return (get_ver_len(game, coor, v_hit_x, v_hit_y));
}

double	from_90__180_hor(t_prog *game, double angle, t_coor *coor)
{
	double	h_hit_x;
	double	h_hit_y;
	double	h_x_step;
	double	h_y_step;

	h_hit_y = (int)game->map.plyr.y * EACH;
	h_hit_x = game->map.plyr.x * EACH - (game->map.plyr.y * EACH - h_hit_y)
		/ -tan(angle);
	h_y_step = EACH;
	h_x_step = h_y_step / -tan(angle);
	while (EACH <= h_hit_y && 0 <= h_hit_x && (h_hit_x - 1) / EACH
		< ft_strlen(game->map.map[(int)(h_hit_y - 1) / EACH]) &&
			game->map.map[(int)h_hit_y / EACH - 1][(int)h_hit_x / EACH] != '1')
	{
		if (((int)(angle / M_PI * 180) == 135 && (angle / M_PI * 180) < 135.0001
			&& game->map.map[(int)(h_hit_y - 1) / EACH][(int)(h_hit_x - 1)
			/ EACH] == '1'))
		{
			h_hit_x = -3 * EACH;
			break ;
		}
		h_hit_x -= h_x_step;
		h_hit_y -= h_y_step;
	}
	return (get_hor_len(game, coor, h_hit_x, h_hit_y));
}

void	from_90__180(t_prog *game, double angle, t_ray *ray)
{
	t_coor	coor;
	double	h_len;
	double	v_len;

	h_len = -1;
	v_len = from_90__180_ver(game, angle, &coor);
	if (angle * 180 / M_PI != 180)
		h_len = from_90__180_hor(game, angle, &coor);
	if ((h_len <= v_len && (int)h_len != -1) || (int)v_len == -1)
	{
		ray->type = HOR;
		ray->hit_x = coor.h_hit_x;
		ray->hit_y = coor.h_hit_y;
		ray->length = h_len;
		ray->is_wall = !found_door(game, ray->hit_y / EACH - 1, ray->hit_x
				/ EACH);
		return ;
	}
	ray->type = VER;
	ray->hit_x = coor.v_hit_x;
	ray->hit_y = coor.v_hit_y;
	ray->length = v_len;
	ray->is_wall = !found_door(game, ray->hit_y / EACH, ray->hit_x / EACH - 1);
}
