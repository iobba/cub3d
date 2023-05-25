/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:59:01 by aybiouss          #+#    #+#             */
/*   Updated: 2022/12/30 12:59:01 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*kept_one(char **str, int newline)
{
	int		l;
	char	*tmp;

	l = ft_strlen(*str);
	tmp = ft_substr(*str, newline, l + 1);
	free(*str);
	*str = NULL;
	return (tmp);
}

char	*returned_line(char **line, char **all, int newline)
{
	*line = ft_substr(*all, 0, newline + 1);
	*all = kept_one(all, newline + 1);
	return (*line);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*all;
	char		*line;
	ssize_t		length;
	int			newline;

	length = read(fd, buf, BUFFER_SIZE);
	if (!all && length >= 0)
		all = ft_strdup("");
	while (length >= 0)
	{
		buf[length] = 0;
		all = ft_strjoine(all, buf);
		if (!length && !all[0])
			break ;
		newline = check_newline(all);
		if (newline != -1)
			return (returned_line(&line, &all, newline));
		else if (!length)
			return (kept_one(&all, 0));
		length = read(fd, buf, BUFFER_SIZE);
	}
	free(all);
	all = NULL;
	return (NULL);
}
