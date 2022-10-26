/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:26:30 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 19:56:41 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen(int n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	if (sign == -1)
		i++;
	return (i);
}

static char	*ft_convertint(char *mem, int n, int len)
{
	mem[len] = '\0';
		len--;
	if (n == 0)
		mem[len] = '0';
	else if (n > 0)
	{
		while (n)
		{
			mem[len] = '0' + (n % 10);
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (n)
		{
			mem[len] = '0' - (n % 10);
			n = n / 10;
			len--;
		}
		mem[len] = '-';
	}
	return (mem);
}

char	*ft_itoa(int n)
{
	char	*mem;
	int		sign;
	int		len;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_intlen(n, sign);
	mem = (char *)malloc(sizeof(*mem) * len + 1);
	if (!mem)
		return (NULL);
	if (n > 2147483647)
		return (0);
	ft_convertint(mem, n, len);
	return (mem);
}
/*
#include <stdio.h>
int     main(void)
{
	printf("%s\n", ft_itoa(2147483649));
	return (0);
}
*/