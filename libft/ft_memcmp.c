/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:59:00 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 20:02:23 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
/*
int main(void)
{
	char s1[] = "42cadet";
	char s2[] = "42cadetabc";
	printf("%d\n", memcmp(s1, s2, 3));
	printf("%d\n", ft_memcmp(s1, s2, 3));
	printf("%d\n", memcmp(s1, s2, 8));
	printf("%d\n", ft_memcmp(s1, s2, 8));

	return (0);
}
*/