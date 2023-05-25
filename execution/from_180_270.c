/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_180_270.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:55:28 by iobba             #+#    #+#             */
/*   Updated: 2023/05/11 18:41:50 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_ver_ln(t_prog *game, t_coor *coor, double _x, double _y)
{
	double	v_len;

	v_len = -1.0;
	if (_x == -3 * EACH)
	{
		_x = coor->v_hit_x;
		_y = coor->v_hit_y;
	}
	v_len = sqrt((game->map.plyr.x * EACH - _x) * (game->map.plyr.x
				* EACH - _x) + (_y - game->map.plyr.y * EACH)
			* (_y - game->map.plyr.y * EACH));
	coor->v_hit_x = _x;
	coor->v_hit_y = _y;
	return (v_len);
}

double	get_hor_ln(t_prog *game, t_coor *coor, double _x, double _y)
{
	double	h_len;

	h_len = -1.0;
	if (_x == -3 * EACH)
	{
		_x = coor->h_hit_x;
		_y = coor->h_hit_y;
	}
	h_len = sqrt((game->map.plyr.x * EACH - _x) * (game->map.plyr.x
				* EACH - _x) + (_y - game->map.plyr.y * EACH)
			* (_y - game->map.plyr.y * EACH));
	coor->h_hit_x = _x;
	coor->h_hit_y = _y;
	return (h_len);
}

double	from_180__270_ver(t_prog *game, double angle, t_coor *coor)
{
	double	_x;
	double	_y;
	double	v_x_step;
	double	v_y_step;

	_x = (int)game->map.plyr.x * EACH;
	_y = (game->map.plyr.y * EACH) + ((game->map.plyr.x * EACH) - _x)
		* tan(angle);
	v_x_step = EACH;
	v_y_step = v_x_step * tan(angle);
	while (0 <= _y && (int)_x / EACH - 1 >= 0 && (int)(_y +1) / EACH
		< game->map.y && _x / EACH < ft_strlen(game->map.map[(int)_y / EACH])
		&& game->map.map[(int)_y / EACH][(int)_x / EACH - 1] != '1')
	{
		if ((int)(angle / M_PI * 180) == 224 && angle / M_PI * 180 > 224.99999
			&& game->map.map[(int)((_y + 1) / EACH)][(int)(_x - 1)
			/ EACH] == '1')
		{
			_x = -3 * EACH;
			break ;
		}
		_x -= v_x_step;
		_y += v_y_step;
	}
	return (get_ver_ln(game, coor, _x, _y));
}

double	from_180__270_hor(t_prog *game, double angle, t_coor *coor)
{
	double	_x;
	double	_y;
	double	h_x_step;
	double	h_y_step;

	_y = ((int)game->map.plyr.y + 1) * EACH;
	_x = game->map.plyr.x * EACH - (_y - game->map.plyr.y
			* EACH) / tan(angle);
	h_y_step = EACH;
	h_x_step = h_y_step / tan(angle);
	while (0 <= _y && 1 <= _x && (int)(_y + 1) / EACH < game->map.y
		&& _x - 1 < EACH * ft_strlen(game->map.map[(int)(_y) / EACH])
		&& game->map.map[(int)(_y / EACH)][(int)(_x) / EACH] != '1')
	{
		if ((int)(angle / M_PI * 180) == 224 && angle / M_PI * 180 > 224.99999
			&& game->map.map[(int)((_y + 1) / EACH)][(int)(_x - 1)
			/ EACH] == '1')
		{
			_x = -3 * EACH;
			break ;
		}
		_x -= h_x_step;
		_y += h_y_step;
	}
	return (get_hor_ln(game, coor, _x, _y));
}

void	from_180__270(t_prog *game, double angle, t_ray *ray)
{
	t_coor		coor;
	double		h_len;
	double		v_len;

	h_len = -1;
	v_len = -1;
	if (angle * 180 / M_PI < 269.9999)
		v_len = from_180__270_ver(game, angle, &coor);
	h_len = from_180__270_hor(game, angle, &coor);
	if ((h_len < v_len && (int)h_len != -1) || (int)v_len == -1)
	{
		ray->type = HOR;
		ray->hit_x = coor.h_hit_x;
		ray->hit_y = coor.h_hit_y;
		ray->length = h_len;
		ray->is_wall = !found_door(game, ray->hit_y / EACH, ray->hit_x / EACH);
		return ;
	}
	ray->type = VER;
	ray->hit_x = coor.v_hit_x;
	ray->hit_y = coor.v_hit_y;
	ray->length = v_len;
	ray->is_wall = !found_door(game, ray->hit_y / EACH, ray->hit_x / EACH - 1);
}
