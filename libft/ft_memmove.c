/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:00:27 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 20:05:03 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = dest;
	s = src;
	if (dest == src || n == 0)
		return (dest);
	if (src < dest)
	{
		d = dest + (n - 1);
		s = src + (n - 1);
		while (n > 0)
		{
			*d-- = *s--;
			n--;
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}
/*
int main(void)
{
	char Like[10] = { "ILikeYou" };
	char Hate[10] = { "IHateYou" };
	char str[] = "12345678";

	printf("memmove before : %s\n", Like);
	ft_memmove(Like + 1, Hate + 1, 4);
	printf("memmove after : %s\n", Like);
	printf("memmove before : %s\n", str);
	ft_memmove(str+3, str +1, 3);
	printf("memmove after : %s\n", str);

	return 0;
}
*/