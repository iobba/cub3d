/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_started.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:16:38 by iobba             #+#    #+#             */
/*   Updated: 2023/05/11 18:35:31 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*which_texture(t_prog *game, int x)
{
	if (game->rays[x].angle > 0 && game->rays[x].angle < M_PI
		&& game->rays[x].type == HOR)
		return (game->no_txtr.addr);
	if (game->rays[x].angle > M_PI && game->rays[x].angle < 2 * M_PI
		&& game->rays[x].type == HOR)
		return (game->so_txtr.addr);
	if ((game->rays[x].angle > 3 * M_PI / 2 || game->rays[x].angle < M_PI / 2)
		&& game->rays[x].type == VER)
		return (game->ea_txtr.addr);
	return (game->we_txtr.addr);
}

void	set_first_direction(t_prog *game)
{
	if (game->map.plyr.pos == 'N')
		game->map.plyr.p_angle = (M_PI / 2) * 180 / M_PI;
	if (game->map.plyr.pos == 'S')
		game->map.plyr.p_angle = (3 * M_PI / 2) * 180 / M_PI;
	if (game->map.plyr.pos == 'E')
		game->map.plyr.p_angle = 0;
	if (game->map.plyr.pos == 'W')
		game->map.plyr.p_angle = (M_PI) * 180 / M_PI;
}

int	open_win(t_prog *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_perror("Error\n", "the initialization of mlx has failed");
	game->data.img = mlx_new_image(game->mlx, MINI_WIDTH, MINI_HIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img,
			&game->data.bits_per_pixel, &game->data.line_length,
			&game->data.endian);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HIGHT, "cub3d");
	game->data_3d.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HIGHT);
	game->data_3d.addr = mlx_get_data_addr(game->data_3d.img,
			&game->data_3d.bits_per_pixel, &game->data_3d.line_length,
			&game->data_3d.endian);
	init_img(game);
	control_hooks(game);
	mlx_loop(game->mlx);
	return (0);
}
