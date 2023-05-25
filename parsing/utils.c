/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:07 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 11:53:32 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen_n(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*line_protection(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_mapfree(line);
	return (line);
}

int	ft_strchr(char const *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (ft_strlen((char *)s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft__int(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	i = 0;
	hay = (char *) haystack;
	if (*needle == '\0')
		return (0);
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0' && len > (i + j))
		{
			if (needle[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
