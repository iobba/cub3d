/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:50:25 by iobba             #+#    #+#             */
/*   Updated: 2023/05/09 16:45:43 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_rays_angle(t_prog *game)
{
	int	i;

	i = 0;
	while (i <= WINDOW_WIDTH)
	{
		game->rays[i].angle = ((game->map.plyr.p_angle + 30) * M_PI / 180)
			- i * (60.0 * M_PI / 180) / 1200;
		if (game->rays[i].angle > 2 * M_PI)
			game->rays[i].angle = game->rays[i].angle - 2 * M_PI;
		if (game->rays[i].angle < 0)
			game->rays[i].angle = game->rays[i].angle + 2 * M_PI;
		i++;
	}
}

void	rays_casting(t_prog *game)
{
	double	angle;
	int		i;

	set_rays_angle(game);
	i = 0;
	while (i <= WINDOW_WIDTH)
	{
		angle = game->rays[i].angle;
		if ((angle * 180 / M_PI <= 90 && angle * 180 / M_PI >= 0)
			|| angle * 180 / M_PI == 360)
			from_0_90(game, angle, &game->rays[i]);
		else if (angle * 180 / M_PI <= 180.001 && angle * 180 / M_PI > 90)
			from_90__180(game, angle, &game->rays[i]);
		else if (angle * 180 / M_PI <= 270.0001 && angle * 180 / M_PI > 180.001)
			from_180__270(game, angle, &game->rays[i]);
		else if (angle * 180 / M_PI < 360 && angle * 180 / M_PI > 270.001)
			from_270__360(game, angle, &game->rays[i]);
		i++;
	}
}
