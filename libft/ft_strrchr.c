/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:35:08 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 19:38:30 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
  char buf[] = "computer program";
  char * ptr;
  int    ch = 'p';
			
  ptr = ft_strrchr(buf, ch);
  printf( "The last occurrence of %c in '%s' is '%s'\n", ch, buf, ptr );
}
*/