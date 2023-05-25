/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:40:43 by iobba             #+#    #+#             */
/*   Updated: 2023/05/20 16:52:49 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_abs(int d)
{
	if (d < 0)
		return (-d);
	return (d);
}

int	count_doors(t_prog *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.y)
	{
		j = 0;
		while (j < game->map.x)
		{
			if (game->map.map[i][j] == '2')
			{
				k++;
			}
			j++;
		}
		i++;
	}
	return (k);
}

void	handle_doors(t_prog *game)
{
	static int	i;
	int			j;
	int			k;

	k = count_doors(game);
	game->nbr_doors = k;
	game->doors = malloc((k + 1) * sizeof(t_doors));
	k = 0;
	if (!game->doors)
		ft_perror("Error\n", "Malloc failed");
	while (++i < game->map.y)
	{
		j = -1;
		while (++j < game->map.x)
		{
			if (game->map.map[i][j] == '2')
			{
				game->doors[k].x = j;
				game->doors[k].y = i;
				game->doors[k].is_closed = 1;
				game->map.map[i][j] = '1';
				k++;
			}
		}
	}
}

int	found_door(t_prog *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < game->nbr_doors)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

void	open_close_door(t_prog *game)
{
	int	i;

	i = 0;
	while (i < game->nbr_doors
		&& !found_door(game, (int)game->map.plyr.y, (int)game->map.plyr.x))
	{
		if (game->map.map[game->doors[i].y][game->doors[i].x] == '1')
			game->map.map[game->doors[i].y][game->doors[i].x] = '0';
		else
			game->map.map[game->doors[i].y][game->doors[i].x] = '1';
		i++;
	}
}
