/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:57:04 by iobba             #+#    #+#             */
/*   Updated: 2023/05/06 11:22:27 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	_which_(t_prog *game, int i, int j)
{
	if (game->map.map[j / MINI][i / MINI] == '0')
		return (IS_BACK_GROUND);
	else if (game->map.map[j / MINI][i / MINI] == '1'
		&& found_door(game, j / MINI, i / MINI))
		return (IS_DOOR);
	else if (game->map.map[j / MINI][i / MINI] == '1')
		return (IS_WALL);
	else if (game->map.map[j / MINI][i / MINI] == ' ')
		return (IS_SPACE);
	return (-1);
}

void	put_pixels(t_prog *game, int x, int y, int _which_)
{
	if (_which_ == IS_BACK_GROUND)
		my_mlx_pixel_put(&game->data, x, y, 0x88FFFF99);
	else if (_which_ == IS_DOOR)
		my_mlx_pixel_put(&game->data, x, y, 0x8833FF33);
	else if (_which_ == IS_WALL)
		my_mlx_pixel_put(&game->data, x, y, 0x00202020);
	else if (_which_ == IS_SPACE)
		my_mlx_pixel_put(&game->data, x, y, 0xFFE0E0E0);
}

void	mini_mini_map(t_prog *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->map.y < MINI_HIGHT / 20)
	{
		i = game->map.y * 20 - 1;
		while (++i < MINI_HIGHT)
		{
			j = -1;
			while (++j < MINI_WIDTH)
				my_mlx_pixel_put(&game->data, j, i, 0xFFE0E0E0);
		}
	}
	i = 0;
	if (game->map.x < MINI_WIDTH / 20)
	{
		i = (game->map.x - 1) * 20 - 1;
		while (++i < MINI_WIDTH)
		{
			j = -1;
			while (++j < MINI_HIGHT)
				my_mlx_pixel_put(&game->data, i, j, 0xFFE0E0E0);
		}
	}
}

void	for_each_coloum(t_prog *game, int j, int m)
{
	int	i;
	int	n;

	if (game->map.plyr.x * MINI >= (game->map.x - 1) * MINI - MINI_WIDTH / 2)
		i = game->p_x - MINI_WIDTH / 2 - (game->p_x - ((game->map.x - 1) * MINI
					- MINI_WIDTH / 2));
	else
		i = game->map.plyr.x * MINI - MINI_WIDTH / 2;
	if (i < 0)
		i = 0;
	n = 0;
	while (!(i >= game->map.x * MINI || n >= MINI_WIDTH))
	{
		if (j == game->p_y && i == game->p_x)
		{
			game->p_x = n;
			game->p_y = m;
		}
		put_pixels(game, n, m, _which_(game, i, j));
		i++;
		n++;
	}
}

void	render_mini_map(t_prog *game)
{
	int	j;
	int	m;

	game->p_x = game->map.plyr.x * MINI;
	game->p_y = game->map.plyr.y * MINI;
	if (game->map.plyr.y * MINI >= game->map.y * MINI - MINI_HIGHT / 2)
		j = game->p_y - MINI_HIGHT / 2 - (game->p_y - (game->map.y * MINI
					- MINI_HIGHT / 2));
	else
		j = game->map.plyr.y * MINI - MINI_HIGHT / 2;
	if (j < 0)
		j = 0;
	m = 0;
	while (!(j >= game->map.y * MINI || m >= MINI_HIGHT))
	{
		for_each_coloum(game, j, m);
		j++;
		m++;
	}
	mini_mini_map(game);
}
