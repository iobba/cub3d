/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:56:27 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/13 15:45:11 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_door(int up, int down, int left, int right)
{
	if ((up == 49 && down == 49) || (left == 49 && right == 49))
		return ;
	else
		ft_perror("Error\n", "Correct the map doors");
}

void	position_door(t_prog *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.x - 1)
	{
		i = 0;
		while (i < game->map.y - 1)
		{
			if (game->map.map[i][j] == '2')
				check_door(game->map.map[i - 1][j], game->map.map[i + 1][j],
					game->map.map[i][j - 1], game->map.map[i][j + 1]);
			i++;
		}
		j++;
	}
}
