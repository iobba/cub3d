/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontally_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:14:35 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/13 15:43:15 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_horizontal_space(char c, char character)
{
	if ((c == '1' || c == ' ') && (character == '1'
			|| character == ' ' || character == '\n'))
		return ;
	else
		ft_perror("Error\n", "Correct the map horizontally");
}

void	check_horizontaly(t_prog *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.y - 1)
	{
		j = 0;
		while (j < game->map.x - 1)
		{
			if (j == 0)
			{
				while (game->map.map[i][j] == ' ')
					j++;
			}
			if (game->map.map[i][j] == ' ')
				check_horizontal_space(game->map.map[i][j - 1],
					game->map.map[i][j + 1]);
			j++;
		}
		i++;
	}
}
