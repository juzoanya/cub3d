/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:54:18 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 19:39:09 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == find[j] && (i + j) < len)
		{
			j++;
			if (find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
/*
int main(void)
{
  //const char *s = "Foo Bar Baz";
  //const char *find = "Bar";
  //char    *ptr;

  printf("%s\n", strnstr("lorem ipsum dolor sit amet", "lorem", 15));
  
  return(0);
}
*/