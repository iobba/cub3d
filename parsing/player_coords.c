/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:16:52 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/18 14:46:59 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	flaging(t_prog *game, double i, double j, int *flag)
{
	game->map.plyr.x = i + 0.5;
	game->map.plyr.y = j + 0.5;
	game->map.plyr.pos = game->map.map[(int)j][(int)i];
	set_first_direction(game);
	game->map.map[(int)j][(int)i] = '0';
	*flag = 9;
	i++;
	return (i);
}

int	check_plyr_coords(t_prog *game)
{
	double			i;
	double			j;
	static int		flag;

	j = 0.0;
	while (j < game->map.y)
	{
		i = 0;
		while (i < game->map.x)
		{
			if (flag == 0 && (game->map.map[(int)j][(int)i] == 'N'
				|| game->map.map[(int)j][(int)i] == 'E'
				|| game->map.map[(int)j][(int)i] == 'W'
				|| game->map.map[(int)j][(int)i] == 'S'))
				i = flaging(game, i, j, &flag);
			if (flag == 9 && (game->map.map[(int)j][(int)i] == 'N'
				|| game->map.map[(int)j][(int)i] == 'E'
				|| game->map.map[(int)j][(int)i] == 'W'
				|| game->map.map[(int)j][(int)i] == 'S'))
				ft_perror("Error\n", "There are more than one plyr in your map");
			i++;
		}
		j++;
	}
	return (flag);
}
