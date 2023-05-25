/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:07:09 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/16 19:04:34 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_longest_line(char *line, int fd, t_prog *game)
{
	int		len;
	int		length;
	int		i;

	i = 0;
	if (ft_strnstr((const char *)line, ",", ft_strlen(line)))
		return (0);
	length = ft_strlen(line);
	while (line)
	{
		len = ft_strlen(line);
		if (len > length)
			length = len;
		if (i > 0)
			free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	game->map.y = i;
	game->map.x = length;
	game->map.map = malloc((game->map.y * sizeof(char *)));
	if (!game->map.map)
		return (0);
	return (length);
}
