/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:26:42 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 15:11:08 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_line_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
		{
			if (!(line[i] == 'F' || line[i] == 'C' || line[i] == ' '
					|| line[i] == ',' || line[i] == '\n'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	rgbtoint(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

void	check_characters(t_prog *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.y - 1)
	{
		j = 0;
		while (j < game->map.x - 1)
		{
			if (game->map.map[i][j] != '\0' && game->map.map[i][j] != ' '
				&& game->map.map[i][j] != '2'
				&& game->map.map[i][j] != '0' && game->map.map[i][j] != '1'
				&& game->map.map[i][j] != 'N' && game->map.map[i][j] != 'W'
				&& game->map.map[i][j] != 'S' && game->map.map[i][j] != 'E'
				&& game->map.map[i][j] != '\n')
				ft_perror("Error\n", "Invalid Character in the map");
			j++;
		}
		i++;
	}
}
