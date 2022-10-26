/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:40:02 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/14 15:16:22 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
/*
int main(void)
{
	char    c;
	int     result;

	c = '5';
	result = ft_isalpha(c);
	printf("When %c is passed, return value is %d\n", c, result);

	c = 'W';
	result = ft_isalpha(c);
	printf("When %c is passed, return value is %d\n", c, result);

	c = 'h';
	result = ft_isalpha(c);
	printf("When %c is passed, return value is %d\n", c, result);

	c = '*';
	result = ft_isalpha(c);
	printf("When %c is passed, return value is %d\n", c, result);
}
*/