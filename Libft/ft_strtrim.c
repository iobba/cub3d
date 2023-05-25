/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:35:00 by aybiouss          #+#    #+#             */
/*   Updated: 2023/03/17 09:48:10 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *set, char s)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*mem;

	if (!s1 || !set)
		return (0);
	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[i] && check(set, s1[i]))
		i++;
	while (len > 0 && check(set, s1[len]))
		len--;
	mem = ft_substr(s1, i, len - i + 1);
	return (mem);
}
