/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:59:51 by iobba             #+#    #+#             */
/*   Updated: 2023/05/24 11:30:18 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_offset_y(int y, double wallstrp_hight)
{
	int	offset_y;
	int	distance_from_top;

	distance_from_top = y + ((int)wallstrp_hight / 2) - (WINDOW_HIGHT / 2);
	offset_y = distance_from_top * (TEXTURE_HIGHT / wallstrp_hight);
	return (offset_y);
}

int	get_offset_x(t_prog *game, int x)
{
	int	offset_x;

	if (game->rays[x].type == VER)
		offset_x = game->rays[x].hit_y % EACH;
	else
		offset_x = game->rays[x].hit_x % EACH;
	return (offset_x);
}

void	draw_wall_and_door(t_prog *game, int x, int y, double wallstrp_hiht)
{
	int	offset_x;
	int	offset_y;
	int	text_color;
	int	index_addr;

	offset_y = get_offset_y(y, wallstrp_hiht);
	offset_x = get_offset_x(game, x);
	index_addr = (TEXTURE_WIDTH * offset_y) + offset_x;
	if (index_addr < TEXTURE_WIDTH * TEXTURE_HIGHT)
	{
		if (game->rays[x].is_wall)
		{
			text_color = ((unsigned int *)which_texture(game, x))[index_addr];
			my_mlx_pixel_put(&game->data_3d, x, y, text_color);
			text_color = ((unsigned int *)game->fire_txtr.addr)[index_addr];
			if (text_color != -16777216)
				my_mlx_pixel_put(&game->data_3d, x, y, text_color);
		}
		else
		{
			text_color = ((unsigned int *)game->door_txtr.addr)[index_addr];
			my_mlx_pixel_put(&game->data_3d, x, y, text_color);
		}
	}
}

double	get_projcted_hight(t_prog *game, int x)
{
	double	correctwall_distance;
	double	distance_projection_plane;
	double	wallstrp_hight;

	distance_projection_plane = (double)(WINDOW_WIDTH / 2)
		/ tan(60.0 / 2 * M_PI / 180);
	correctwall_distance = (double)game->rays[x].length
		* cos(game->map.plyr.p_angle * M_PI / 180 - game->rays[x].angle);
	wallstrp_hight = (EACH / correctwall_distance) * distance_projection_plane;
	wallstrp_hight *= WALL_HIGHT;
	return (wallstrp_hight);
}

void	drawing_walls(t_prog *game)
{
	int		x;
	int		y;
	double	wallstrp_hight;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		wallstrp_hight = get_projcted_hight(game, x);
		while (y < WINDOW_HIGHT)
		{
			if (y <= (WINDOW_HIGHT / 2) - wallstrp_hight / 2)
				my_mlx_pixel_put(&game->data_3d, x, y, game->map.ceil_clr);
			else if ((WINDOW_HIGHT - wallstrp_hight) / 2 + wallstrp_hight < y)
				my_mlx_pixel_put(&game->data_3d, x, y, game->map.floor_colour);
			else
				draw_wall_and_door(game, x, y, wallstrp_hight);
			y++;
		}
		x++;
	}
}
