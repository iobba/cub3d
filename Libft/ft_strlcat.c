/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:06:55 by aybiouss          #+#    #+#             */
/*   Updated: 2023/03/21 21:00:26 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t length)
{
	size_t	i;
	size_t	dl;
	size_t	game;
	size_t	j;

	i = 0;
	dl = ft_strlen(dst);
	game = ft_strlen(src);
	j = dl;
	if (length == 0 || dl >= length)
		return (length + game);
	while ((length - dl - 1) > i && src[i] != '\0')
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (game + dl);
}
