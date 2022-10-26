/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:26:37 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/22 16:47:11 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_count(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static void	get_next_str(char **next_str, size_t *str_len, char c)
{
	size_t	i;

	*next_str += *str_len;
	*str_len = 0;
	i = 0;
	while ((*next_str)[i] == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**mem;
	char	*next_str;
	size_t	str_len;
	size_t	i;

	mem = (char **)malloc(sizeof(*mem) * (str_count(s, c) + 1));
	if (mem == NULL)
		return (NULL);
	i = 0;
	next_str = (char *)s;
	str_len = 0;
	while (i < str_count(s, c))
	{
		get_next_str(&next_str, &str_len, c);
		mem[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (mem[i] == NULL)
			return (NULL);
		ft_strlcpy(mem[i], next_str, str_len + 1);
		i++;
	}
	mem[i] = NULL;
	return (mem);
}
