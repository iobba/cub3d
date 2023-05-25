/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:46:03 by iobba             #+#    #+#             */
/*   Updated: 2023/05/16 17:56:54 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(t_prog *game)
{
	game->map.plyr.p_angle -= ROTATION_SPEED;
	if (game->map.plyr.p_angle < 0)
		game->map.plyr.p_angle = 360 + game->map.plyr.p_angle;
}

void	rotate_left(t_prog *game)
{
	game->map.plyr.p_angle += ROTATION_SPEED;
	if (game->map.plyr.p_angle > 360)
		game->map.plyr.p_angle = game->map.plyr.p_angle - 360;
}

int	set_keys(int key, t_prog *game)
{
	if (key == 53)
	{
		exit(0);
	}
	if (key == 0)
		game->move_to = MOVE_LEFT;
	if (key == 2)
		game->move_to = MOVE_RIGHT;
	if (key == 1 || key == 125)
		game->move_to = MOVE_DOWN;
	if (key == 13 || key == 126)
		game->move_to = MOVE_UP;
	if (key == 124)
		game->rotate_to = ROTATE_RIGHT;
	if (key == 123)
		game->rotate_to = ROTATE_LEFT;
	if (key == 83 || key == 82)
		game->is_mouse_works = key - 82;
	if (key == 49)
		open_close_door(game);
	return (0);
}

int	unset_keys(int key, t_prog *game)
{
	if (key == 0)
		game->move_to = 0;
	if (key == 2)
		game->move_to = 0;
	if (key == 1 || key == 125)
		game->move_to = 0;
	if (key == 13 || key == 126)
		game->move_to = 0;
	if (key == 124)
		game->rotate_to = 0;
	if (key == 123)
		game->rotate_to = 0;
	return (0);
}

int	keys_func(t_prog *game)
{
	if (game->move_to == MOVE_LEFT)
		move_to_(game, game->map.plyr.p_angle - 90, -1, 1);
	if (game->move_to == MOVE_RIGHT)
		move_to_(game, game->map.plyr.p_angle + 90, -1, 1);
	if (game->move_to == MOVE_DOWN)
		move_to_(game, game->map.plyr.p_angle, -1, 1);
	if (game->move_to == MOVE_UP)
		move_to_(game, game->map.plyr.p_angle, 1, -1);
	if (game->rotate_to == ROTATE_RIGHT)
		rotate_right(game);
	if (game->rotate_to == ROTATE_LEFT)
		rotate_left(game);
	return (0);
}
