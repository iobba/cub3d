/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:45:48 by iobba             #+#    #+#             */
/*   Updated: 2023/05/11 17:16:01 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_addr_animation(t_prog *game)
{
	game->fire_1.addr = mlx_get_data_addr(game->fire_1.img,
			&game->fire_1.bits_per_pixel, &game->fire_1.line_length,
			&game->fire_1.endian);
	game->fire_2.addr = mlx_get_data_addr(game->fire_2.img,
			&game->fire_2.bits_per_pixel, &game->fire_2.line_length,
			&game->fire_2.endian);
	game->fire_3.addr = mlx_get_data_addr(game->fire_3.img,
			&game->fire_3.bits_per_pixel, &game->fire_3.line_length,
			&game->fire_3.endian);
	game->fire_4.addr = mlx_get_data_addr(game->fire_4.img,
			&game->fire_4.bits_per_pixel, &game->fire_4.line_length,
			&game->fire_4.endian);
	game->fire_5.addr = mlx_get_data_addr(game->fire_5.img,
			&game->fire_5.bits_per_pixel, &game->fire_5.line_length,
			&game->fire_5.endian);
	game->fire_6.addr = mlx_get_data_addr(game->fire_6.img,
			&game->fire_6.bits_per_pixel, &game->fire_6.line_length,
			&game->fire_6.endian);
	game->fire_7.addr = mlx_get_data_addr(game->fire_7.img,
			&game->fire_7.bits_per_pixel, &game->fire_7.line_length,
			&game->fire_7.endian);
	game->fire_txtr = game->fire_1;
}

void	get_addr(t_prog *game)
{
	if (!game->door_txtr.img || !game->fire_1.img
		|| !game->fire_2.img || !game->fire_3.img || !game->fire_7.img
		||!game->fire_4.img || !game->fire_5.img || !game->fire_6.img)
		ft_perror("Error\n", "...xpm No such file or directory");
	game->door_txtr.addr = mlx_get_data_addr(game->door_txtr.img,
			&game->door_txtr.bits_per_pixel, &game->door_txtr.line_length,
			&game->door_txtr.endian);
	get_addr_animation(game);
}

void	get_addr_walls(t_prog *game)
{
	game->no_txtr.addr = mlx_get_data_addr(game->no_txtr.img,
			&game->no_txtr.bits_per_pixel, &game->no_txtr.line_length,
			&game->no_txtr.endian);
	game->so_txtr.addr = mlx_get_data_addr(game->so_txtr.img,
			&game->so_txtr.bits_per_pixel, &game->so_txtr.line_length,
			&game->so_txtr.endian);
	game->we_txtr.addr = mlx_get_data_addr(game->we_txtr.img,
			&game->we_txtr.bits_per_pixel, &game->we_txtr.line_length,
			&game->we_txtr.endian);
	game->ea_txtr.addr = mlx_get_data_addr(game->ea_txtr.img,
			&game->ea_txtr.bits_per_pixel, &game->ea_txtr.line_length,
			&game->ea_txtr.endian);
}

void	get_img_walls(t_prog *game)
{
	int	h;
	int	w;

	game->no_txtr.img = mlx_xpm_file_to_image(game->mlx,
			game->map.north, &w, &h);
	game->so_txtr.img = mlx_xpm_file_to_image(game->mlx,
			game->map.south, &w, &h);
	game->we_txtr.img = mlx_xpm_file_to_image(game->mlx,
			game->map.west, &w, &h);
	game->ea_txtr.img = mlx_xpm_file_to_image(game->mlx,
			game->map.east, &w, &h);
	if (!game->no_txtr.img || !game->so_txtr.img
		|| !game->we_txtr.img || !game->ea_txtr.img)
		ft_perror("Error\n", "...xpm No such file or directory");
	get_addr_walls(game);
}

void	init_img(t_prog *game)
{
	int	h;
	int	w;

	get_img_walls(game);
	game->door_txtr.img = mlx_xpm_file_to_image(game->mlx,
			"./img/door.xpm", &w, &h);
	game->fire_1.img = mlx_xpm_file_to_image(game->mlx,
			"./img/fire_11.xpm", &w, &h);
	game->fire_2.img = mlx_xpm_file_to_image(game->mlx,
			"./img/fire_22.xpm", &w, &h);
	game->fire_3.img = mlx_xpm_file_to_image(game->mlx,
			"./img/fire_33.xpm", &w, &h);
	game->fire_4.img = mlx_xpm_file_to_image(game->mlx,
			"./img/fire_44.xpm", &w, &h);
	game->fire_5.img = mlx_xpm_file_to_image(game->mlx,
			"./img/fire_55.xpm", &w, &h);
	game->fire_6.img = mlx_xpm_file_to_image(game->mlx,
			"./img/fire_66.xpm", &w, &h);
	game->fire_7.img = mlx_xpm_file_to_image(game->mlx,
			"./img/fire_77.xpm", &w, &h);
	get_addr(game);
}
