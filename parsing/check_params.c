/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:44 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 14:34:40 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	checker(t_prog *game)
{
	if (!game->map.south || !game->map.north
		|| !game->map.west || !game->map.east || !game->map.floor_colour
		|| !game->map.ceil_clr)
		ft_perror("Error\n", "Parameters are missing in the map");
}

void	checkparam(char *line, t_prog *game)
{
	char		**split;
	static int	i;

	split = ft_split(line, ' ');
	if (i > 3)
	{
		freeing(split);
		error_infos();
	}
	else if (!ft_strcmp(split[0], "NO"))
		game->map.north = ft_strtrim(split[1], "\n");
	else if (!ft_strcmp(split[0], "SO"))
		game->map.south = ft_strtrim(split[1], "\n");
	else if (!ft_strcmp(split[0], "WE"))
		game->map.west = ft_strtrim(split[1], "\n");
	else if (!ft_strcmp(split[0], "EA"))
		game->map.east = ft_strtrim(split[1], "\n");
	i++;
	freeing(split);
}
