/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:54 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/20 16:46:17 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_continuation(t_prog *game)
{
	game->map.map = NULL;
	game->map.y = 0;
	game->map.x = 0;
	game->map.floor_colour = 0;
	game->map.ceil_clr = 0;
	game->map.north = NULL;
	game->map.south = NULL;
	game->map.east = NULL;
	game->map.west = NULL;
}

t_prog	*init_game(void)
{
	t_prog	*game;

	game = malloc(sizeof(t_prog));
	init_continuation(game);
	game->map.plyr.move_speed = 2.0;
	game->rays = malloc(1201 * sizeof(t_ray));
	if (!game || !game->rays)
		return (NULL);
	game->move_to = 0;
	game->rotate_to = 0;
	game->cursor_x = 0;
	game->cursor_y = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->start = 0;
	game->is_mouse_works = 0;
	game->nbr_doors = 0;
	game->loop_var = 0;
	game->map.plyr.p_angle = 0;
	return (game);
}
