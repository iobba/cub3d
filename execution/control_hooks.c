/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:02:27 by iobba             #+#    #+#             */
/*   Updated: 2023/05/20 16:56:37 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(t_prog *game)
{
	(void)game;
	exit(0);
	return (0);
}

int	control_mouse(int x, int y, t_prog *game)
{
	(void)y;
	if (game->start == 0)
		game->start = 1;
	else if (game->cursor_x != x && game->is_mouse_works && MOUSE_SPEED > 0)
	{
		game->map.plyr.p_angle += (game->cursor_x - x) * MOUSE_SPEED;
		if (game->map.plyr.p_angle < 0)
			game->map.plyr.p_angle = 360 + game->map.plyr.p_angle;
		if (game->map.plyr.p_angle > 360)
			game->map.plyr.p_angle = game->map.plyr.p_angle - 360;
	}
	game->cursor_x = x;
	return (0);
}

int	put_fire(t_prog *game)
{
	game->loop_var++;
	if (game->loop_var == 1)
		game->fire_txtr = game->fire_1;
	if (game->loop_var == 10)
		game->fire_txtr = game->fire_2;
	if (game->loop_var == 20)
		game->fire_txtr = game->fire_3;
	if (game->loop_var == 30)
		game->fire_txtr = game->fire_4;
	if (game->loop_var == 40)
		game->fire_txtr = game->fire_5;
	if (game->loop_var == 50)
		game->fire_txtr = game->fire_6;
	if (game->loop_var == 60)
		game->fire_txtr = game->fire_7;
	if (game->loop_var == 70)
		game->loop_var = 0;
	return (0);
}

int	looping_function(t_prog *game)
{
	put_fire(game);
	keys_func(game);
	render_all(game);
	return (0);
}

void	control_hooks(t_prog *game)
{
	mlx_hook(game->win, 2, 0, &set_keys, game);
	mlx_hook(game->win, 3, 0, &unset_keys, game);
	mlx_loop_hook(game->mlx, &looping_function, game);
	mlx_hook(game->win, 17, 0, &ft_close, game);
	mlx_hook(game->win, 6, 0, &control_mouse, game);
}
