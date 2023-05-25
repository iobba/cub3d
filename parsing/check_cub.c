/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:05:04 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 11:04:57 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	checking_cub(char *av)
{
	int	length;

	length = ft_strlen(av);
	if (ft_strnstr(&av[length - 4], ".cub", 5))
		return (1);
	else
		return (0);
}
