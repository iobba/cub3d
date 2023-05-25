/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:07:02 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 11:03:36 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(void)
{
	write(2, "Error\n", 7);
	write(2, "Correct the map", 16);
	exit(EXIT_FAILURE);
}

void	error_name(void)
{
	write(2, "Error\n", 7);
	write(2, "Wrong file name", 16);
	exit(EXIT_FAILURE);
}

void	error_file(void)
{
	write(2, "Error\n", 7);
	write(2, "No such file or directory", 26);
	exit(EXIT_FAILURE);
}

void	error_image(t_prog *game)
{
	(void)game;
	write(2, "Error\n", 7);
	write(2, "Error image", 12);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *msg, char *utils)
{
	write(2, msg, ft_strlen(msg));
	if (utils)
		write(2, utils, ft_strlen(utils));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
