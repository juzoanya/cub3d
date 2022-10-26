/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:26:49 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/20 19:25:50 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int main(void)
{
	char s1[] = "ABCDEF";
	char s2[] = "GHIJKL";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/