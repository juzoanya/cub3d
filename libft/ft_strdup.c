/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:37:28 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/20 19:25:36 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	//char set[] = "\t \n";
	printf("%s\n", ft_strdup(str));
	return (0);
}
*/