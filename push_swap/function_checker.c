/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:53:21 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/27 22:53:51 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tab;
	size_t	i;

	tab = (char *)s;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			tab[i] = 0;
			i++;
		}
	}
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	size_t	i;
	size_t	length;

	length = ft_strlen(s1);
	tab = malloc(length + 1 * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		tab[i] = s1[i];
		++i;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((char)*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	line[100];
	int		ret;
	char	c;
	int		i;

	i = 0;
	ret = 1;
	ft_bzero(line, 100);
	while ((ret > 0))
	{
		ret = read(fd, &c, 1);
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	if (line[0] == 0)
		return (NULL);
	return (ft_strdup(line));
}
