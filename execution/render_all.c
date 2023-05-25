/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:26:34 by iobba             #+#    #+#             */
/*   Updated: 2023/05/23 21:12:37 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	identify_player(t_prog *game, int x, int y)
{
	double	_x;
	double	_y;
	int		i;

	i = 1;
	while (i < 20)
	{
		_x = x + cos(game->map.plyr.p_angle * M_PI / 180) * i;
		_y = y - sin(game->map.plyr.p_angle * M_PI / 180) * i;
		my_mlx_pixel_put(&game->data, _x, _y, 0x00FF3333);
		i++;
	}
	my_mlx_pixel_put(&game->data, x, y, 0x000000FF);
	my_mlx_pixel_put(&game->data, x - 1, y, 0x000000FF);
	my_mlx_pixel_put(&game->data, x, y - 1, 0x000000FF);
	my_mlx_pixel_put(&game->data, x, y + 1, 0x000000FF);
	my_mlx_pixel_put(&game->data, x + 1, y, 0x000000FF);
	my_mlx_pixel_put(&game->data, x - 1, y + 1, 0x000000FF);
	my_mlx_pixel_put(&game->data, x - 1, y - 1, 0x000000FF);
	my_mlx_pixel_put(&game->data, x + 1, y - 1, 0x000000FF);
	my_mlx_pixel_put(&game->data, x + 1, y + 1, 0x000000FF);
}

void	render_all(t_prog *game)
{
	render_mini_map(game);
	identify_player(game, game->p_x, game->p_y);
	rays_casting(game);
	drawing_walls(game);
	mlx_put_image_to_window(game->mlx, game->win, game->data_3d.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->data.img, 0, 0);
}
