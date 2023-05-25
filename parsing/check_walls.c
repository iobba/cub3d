/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:04:58 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 09:45:38 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*protection_malloc(t_prog *game)
{
	char	**new_map;

	new_map = NULL;
	if (game->map.y)
		new_map = malloc(sizeof(char *) * game->map.y + 1);
	else
		ft_perror("Error\n", "Correct your map");
	if (!new_map)
		return (NULL);
	return (new_map);
}

void	rectangular_map(t_prog *game, int length)
{
	int		i;
	int		len;
	char	**new_map;

	i = 0;
	new_map = protection_malloc(game);
	while (i < game->map.y)
	{
		len = ft_strlen(game->map.map[i]);
		if (len < length)
		{
			if (game->map.map[i][len - 1] == '\n')
				new_map[i] = ft_realloc(game->map.map[i],
						length, len - 1);
			else
				new_map[i] = ft_realloc(game->map.map[i],
						length, len);
		}
		else
			new_map[i] = game->map.map[i];
		i++;
	}
	new_map[game->map.y - 1][length - 1] = '\0';
	free(game->map.map);
	game->map.map = new_map;
}

int	check_last_line(t_prog *game)
{
	int	i;

	i = 0;
	while (i < game->map.x - 1)
	{
		if (game->map.map[game->map.y - 1][i] == ' '
			|| game->map.map[game->map.y - 1][i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_first_line(t_prog *game)
{
	int	i;

	i = 0;
	while (i < game->map.x - 1)
	{
		if (game->map.map[0][i] == '1' || game->map.map[0][i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_walls(t_prog *game)
{
	static int	i;
	int			j;

	while (game->map.y - 1 > i)
	{
		j = 0;
		while (game->map.map[i][j] == ' ' || game->map.map[i][j] == '\n')
			j++;
		if (game->map.map[i][j] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (game->map.y - 1 > i)
	{
		j = game->map.x - 1;
		while (game->map.map[i][j] == ' ' || game->map.map[i][j] == '\n')
			j--;
		if (game->map.map[i][j] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}
