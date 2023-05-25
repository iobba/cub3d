/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:18:32 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/15 13:35:18 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_realloc(void *line, size_t size, int len)
{
	void	*new_ptr;

	if (!line)
	{
		line = malloc(size + 1);
		return (line);
	}
	if (!size)
		return (free(line), NULL);
	new_ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!new_ptr)
		return (free(new_ptr), free(line), NULL);
	ft_memcpy(new_ptr, line, len);
	while (len < (int)size - 1)
	{
		((char *)new_ptr)[len] = ' ';
		len++;
	}
	((char *)new_ptr)[len++] = '\n';
	((char *)new_ptr)[len] = '\0';
	free(line);
	return (new_ptr);
}
