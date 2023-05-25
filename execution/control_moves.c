/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:52:52 by iobba             #+#    #+#             */
/*   Updated: 2023/05/24 15:32:04 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_next_step_dangerous(t_prog *game, double l_dx, double l_dy)
{
	double	dx;
	double	dy;

	dx = game->map.plyr.x;
	dy = game->map.plyr.y;
	if (((int)dx != (int)l_dx || (int)dy != (int)l_dy)
		&& (((l_dy - 1 >= 0 && l_dx - 1 >= 0
					&& game->map.map[(int)l_dy - 1][(int)l_dx] == '1'
				&& game->map.map[(int)l_dy][(int)l_dx - 1] == '1')
		&& (game->map.map[(int)dy + 1][(int)dx] == '1'
		&& game->map.map[(int)dy][(int)dx + 1] == '1'))
		|| ((game->map.map[(int)dy - 1][(int)dx] == '1'
		&& game->map.map[(int)dy][(int)dx - 1] == '1')
		&& (game->map.map[(int)l_dy + 1][(int)l_dx] == '1'
		&& game->map.map[(int)l_dy][(int)l_dx + 1] == '1'))
		|| ((l_dy - 1 >= 0 && game->map.map[(int)l_dy - 1][(int)l_dx] == '1'
		&& game->map.map[(int)l_dy][(int)l_dx + 1] == '1')
		&& (game->map.map[(int)dy][(int)dx - 1] == '1'
		&& game->map.map[(int)dy + 1][(int)dx] == '1'))
		|| ((game->map.map[(int)dy - 1][(int)dx] == '1'
		&& game->map.map[(int)dy][(int)dx + 1] == '1')
		&& (l_dx - 1 >= 0 && game->map.map[(int)l_dy][(int)l_dx - 1] == '1'
		&& game->map.map[(int)l_dy + 1][(int)l_dx] == '1'))))
		return (0);
	return (1);
}

int	between_walls(t_prog *game, double l_dx, double l_dy)
{
	double	dx;
	double	dy;

	dx = game->map.plyr.x;
	dy = game->map.plyr.y;
	if (l_dx >= 0 && l_dy >= 0 && dx - 1 > 0 && dy - 1 > 0
		&& game->map.map[(int)l_dy] && game->map.map[(int)dy + 1]
		&& l_dx + 1 < ft_strlen(game->map.map[(int)l_dy])
		&& dx + 1 < ft_strlen(game->map.map[(int)dy]))
	{
		if (!(((int)dy == (int)l_dy && (int)dx == (int)l_dx - 1)
				|| ((int)dy == (int)l_dy && (int)dx == (int)l_dx + 1)
				|| ((int)dy == (int)l_dy - 1 && (int)dx == (int)l_dx)
				|| ((int)dy == (int)l_dy + 1 && (int)dx == (int)l_dx)))
			return (is_next_step_dangerous(game, l_dx, l_dy));
	}
	return (1);
}

void	move_to_(t_prog *game, int angle, int _cos, int _sin)
{
	double	next_x;
	double	next_y;

	next_x = game->map.plyr.x + _cos * cos(angle * M_PI / 180) / SLOWING_DOWN;
	next_y = game->map.plyr.y + _sin * sin(angle * M_PI / 180) / SLOWING_DOWN;
	if (game->map.map[(int)next_y][(int)next_x] != '1'
		&& between_walls(game, next_x, next_y))
	{
		game->map.plyr.x = game->map.plyr.x + _cos * cos(angle * M_PI / 180)
			/ SLOWING_DOWN;
		game->map.plyr.y = game->map.plyr.y + _sin * sin(angle * M_PI / 180)
			/ SLOWING_DOWN;
	}
	else if (game->map.map[(int)game->map.plyr.y][(int)next_x] != '1'
		&& between_walls(game, next_x, game->map.plyr.y))
		game->map.plyr.x = game->map.plyr.x + _cos * cos(angle * M_PI / 180)
			/ SLOWING_DOWN;
	else if (game->map.map[(int)next_y][(int)game->map.plyr.x] != '1'
		&& between_walls(game, game->map.plyr.x, next_y))
		game->map.plyr.y = game->map.plyr.y + _sin * sin(angle * M_PI / 180)
			/ SLOWING_DOWN;
}
