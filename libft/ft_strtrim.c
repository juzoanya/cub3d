/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:27:01 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/20 19:26:10 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_strstart(char const *s1, char const *set, unsigned int start)
{
	while (s1[start])
	{
		if (ft_strchr(set, s1[start]) == 0)
			break ;
		start++;
	}
	return (start);
}

static int	ft_strend(char const *s1, char const *set, unsigned int end)
{
	while (s1[end - 1])
	{
		if (ft_strchr(set, s1[end - 1]) == 0)
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*mem;
	unsigned int	start;
	unsigned int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	start = ft_strstart(s1, set, start);
	if (end > start)
		end = ft_strend(s1, set, end);
	mem = (char *)malloc(sizeof(*mem) * (end - start + 1));
	if (mem == NULL)
		return (NULL);
	ft_strlcpy(mem, &s1[start], end - start + 1);
	return (mem);
}
/*
int main(void)
{
	char s1[] = "          ";
	char set[] = "\t \n";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/