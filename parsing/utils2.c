/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:13:10 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/13 15:35:16 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_mapfree(char *line)
{
	free(line);
	write(2, "Error\n", 7);
	write(2, "Correct the map", 16);
	exit(EXIT_FAILURE);
}

void	error_infos(void)
{
	write(2, "Error\n", 7);
	write(2, "Correct your .cub file\n", 23);
	exit(EXIT_FAILURE);
}

char	**freeing(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

void	error_infos2(void)
{
	write(2, "Error\n", 7);
	write(2, "Correct your .cub file colours", 23);
	exit(EXIT_FAILURE);
}
