/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:58:37 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/12 20:20:14 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}
/*
int main(void)
{
	char str[50];
	int len;

	strcpy(str, "This is my 42 project.");

	len = ft_strlen(str);
	printf("Length of |%s| is |%d|\n", str, len);

	return(0);
}
*/