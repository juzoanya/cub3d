/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:03:50 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/15 17:12:31 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*mem;

	i = 0;
	mem = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mem == NULL)
		return (NULL);
	while (*s != '\0')
	{
		mem[i] = *s;
		i++;
		s++;
	}
	mem[i] = '\0';
	return (mem);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		n;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	n = 0;
	while (*s != '\0')
	{
		if (n + 1 < size)
		{
			*d = *s;
			d++;
		}
		s++;
		n++;
	}
	if (size)
		*d = '\0';
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	mem = (char *)malloc(sizeof(*mem) * (len + 1));
	if ((s1 == NULL || s2 == NULL) || mem == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		mem[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		mem[i] = *s2++;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	size;

	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (len < size)
		mem = (char *)malloc(sizeof(*mem) * len + 1);
	else
		mem = (char *)malloc(sizeof(*mem) * size - start + 1);
	ft_strlcpy(mem, s + start, len + 1);
	return (mem);
}
