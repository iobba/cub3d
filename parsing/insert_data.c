/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:14:19 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 15:10:42 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	getting_map(t_prog *game, char *line, int fd)
{
	int		i;
	int		flag;
	char	*lines;

	i = 0;
	flag = 0;
	while (game->map.y > i)
	{
		if (!flag)
		{
			game->map.map[i] = line;
			i++;
			flag++;
		}
		lines = get_next_line(fd);
		if (lines && lines[0] != '\n')
			game->map.map[i] = lines;
		else
			ft_perror("Error\n", "Correct the map");
		i++;
	}
}

void	valid_path(t_prog *game)
{
	check_characters(game);
	if (!check_walls(game) || !check_last_line(game)
		|| !check_first_line(game))
	{
		printf("Error\n");
		exit(1);
	}
	check_horizontaly(game);
	check_verticaly(game);
	if (!check_plyr_coords(game))
		ft_perror("Error\n", "There is no player in the map");
	position_door(game);
}

void	fullfil_map(char *av, t_prog *game, int length)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_file();
	line = line_protection(fd);
	while (line)
	{
		if ((ft_strnstr((const char *)line, ".xpm", ft_strlen(line)))
			|| ft_strchr(line, ',') != -1 || line[0] == '\n' || (line[0] == ' '
				&& !ft_strnstr((const char *)line, "1", ft_strlen(line))))
		{
			free(line);
			line = get_next_line(fd);
		}
		else if (ft_strnstr((const char *)line, "1", ft_strlen(line)))
			break ;
		else
			ft_perror("Error\n", "Correct your map");
	}
	getting_map(game, line, fd);
	close(fd);
	rectangular_map(game, length);
	valid_path(game);
}

int	check_first(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || (line[i] == '\n' && line[i + 1] == '\0'))
			;
		else
			return (1);
		i++;
	}
	return (0);
}

void	insert_data(char *av, t_prog **game)
{
	int			fd;
	static int	length;
	char		*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_file();
	line = line_protection(fd);
	while (line)
	{
		if (ft_strnstr((const char *)line, ".xpm", ft_strlen(line)))
			checkparam(line, *game);
		else if (ft_strchr(line, ',') != -1)
			check_colours(line, *game);
		else if (ft_strnstr((const char *)line, "1", ft_strlen(line)))
			length = check_longest_line(line, fd, *game);
		else if (check_first(line))
			ft_perror("Error\n", "Correct your map");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	checker(*game);
	fullfil_map(av, *game, length);
}
