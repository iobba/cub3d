/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:35:37 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 15:19:45 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_prog	*game;

	if (ac != 2)
		exit(EXIT_FAILURE);
	game = init_game();
	if (!game)
		return (1);
	check_map(av[1], game);
	handle_doors(game);
	open_win(game);
	exit(1);
}
