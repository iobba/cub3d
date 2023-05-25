/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:58:47 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 11:05:16 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(char *av, t_prog *game)
{
	if (!checking_cub(av))
		error_name();
	insert_data(av, &game);
}
