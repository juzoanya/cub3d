/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:50:45 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 20:04:04 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == s)
		return (d);
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
/*
int main(void)
{
  char str[] = "memcpy test!";
  char str1[30];
  char str2[30];

  ft_memcpy(str1, str, strlen(str)+1);
  ft_memcpy(str2, "copy", 5);
  printf("str: %s\nstr1 : %s\nstr2: %s\n",str,str1,str2);
  return (0);
}
*/