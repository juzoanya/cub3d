/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:40:14 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 19:54:22 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
int main(void)
{
	int ch = 0x7c;

	while (ch <= 0x82)
	{
		printf("%#04x   ", ch);
		if (ft_isascii(ch))
		{
			printf("The character is %c\n", ch);
		}
		else
		{
			printf("Cannot be represented by an ASCII character\n");
		}
		ch++;
	}
	return (0);
}
*/