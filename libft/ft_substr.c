/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:27:08 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/21 19:33:51 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>
int main(void)
{
	char    s[] = "lorem ipsum dolor sit amet";
	int st = 400;
	int     len = 20;
	printf("%s\n", ft_substr(s, st, len));
	return (0);
}
*/