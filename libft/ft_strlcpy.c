/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:30:52 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 20:19:46 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		n;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	n = 0;
	while (*s != '\0')
	{
		if (n + 1 < size)
		{
			*d = *s;
			d++;
		}
		s++;
		n++;
	}
	if (size)
		*d = '\0';
	return (n);
}
/*void test(int size)
{
	char string[] = "Hello there, Venus";
	char buffer[19];
	int r;

	r = ft_strlcpy(buffer, string, size);

	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}

int main()
{
	//test(19);
	//test(10);
	//test(1);
	test(0);

	return(0);
}
*/