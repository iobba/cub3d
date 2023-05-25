/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:20:51 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 15:17:25 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_num(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

void	check_comma(char *line)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (!check_line_chars(line))
		ft_perror("Error\n", "Correct your colours");
	split = ft_split(line, ' ');
	if (split[2] && check_num(split[2]))
		ft_perror("Error\n", "Correct your colours");
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j == 2)
	{
		freeing(split);
		return ;
	}
	else
		ft_perror("Error\n", "Correct the colours");
}

char	**checks_colours(char *split)
{
	int		i;
	int		j;
	char	**colours;

	i = 0;
	colours = ft_split(split, ',');
	while (colours[i])
	{
		j = 0;
		if (ft_atoi(colours[i]) > 255)
			ft_perror("Error\n", "RGB colours should be less than 255.");
		while (colours[i][j])
		{
			if (!ft_isdigit(colours[i][j]) && colours[i][j] != '\n')
				ft_perror("Error\n", "RGB should contain only numbers.");
			j++;
		}
		i++;
	}
	if (i > 3)
		ft_perror("Error\n", "There are more than 3 colours");
	return (colours);
}

void	fill_colours(t_prog *game, char **split, char **colours)
{
	if (!ft_strcmp(split[0], "F"))
	{
		if (colours[0] && colours[1] && colours[2])
			game->map.floor_colour = rgbtoint(ft_atoi(colours[0]),
					ft_atoi(colours[1]), ft_atoi(colours[2]));
		else
			ft_perror("Error\n", "Missing a colour");
	}
	else if (!ft_strcmp(split[0], "C"))
	{
		if (colours[0] && colours[1] && colours[2])
			game->map.ceil_clr = rgbtoint(ft_atoi(colours[0]),
					ft_atoi(colours[1]), ft_atoi(colours[2]));
		else
			ft_perror("Error\n", "Missing a colour");
	}
	else
		ft_perror("Error\n", "Correct your .cub file colours");
}

void	check_colours(char *line, t_prog *game)
{
	char		**split;
	static char	**colours;
	static int	k;

	if (k > 1)
		ft_perror("Error\n", "Only 2 colours needed");
	check_comma(line);
	split = ft_split(line, ' ');
	colours = checks_colours(split[1]);
	fill_colours(game, split, colours);
	freeing(split);
	freeing(colours);
	k++;
}
