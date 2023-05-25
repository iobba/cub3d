/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertically_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:14:22 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/13 15:34:54 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_vertical_space(char c, char character)
{
	if (c != '0' && character != '0')
		return ;
	else
		ft_perror("Error\n", "Correct the map vertically");
}

void	check_verticaly(t_prog *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.x - 1)
	{
		i = 0;
		while (i < game->map.y - 1)
		{
			if (game->map.map[i][j] == ' ' && i == 0)
				check_vertical_space('1', game->map.map[i + 1][j]);
			else if (game->map.map[i][j] == ' ' && i == game->map.y - 2)
				check_vertical_space(game->map.map[i - 1][j], '1');
			else if (game->map.map[i][j] == ' ' && i > 0)
				check_vertical_space(game->map.map[i - 1][j],
					game->map.map[i + 1][j]);
			i++;
		}
		j++;
	}
}
