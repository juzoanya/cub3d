/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:36:19 by juzoanya          #+#    #+#             */
/*   Updated: 2022/10/25 19:07:23 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_file_open(void)
{
	ft_putendl_fd("File Open Error!", 1);
	exit(0);
}

void	err_file_close(void)
{
	ft_putendl_fd("File Close Error!", 1);
	exit(0);
}

void	err_extension(void)
{
	ft_putendl_fd("Extension Error!", 1);
	exit(0);
}

void	err_map_char(int n)
{
	if (n == 0)
	{
		ft_putendl_fd("Invalid Map Character!", 1);
		exit(0);
	}
	else if (n == 1)
	{
		ft_putendl_fd("Invalid Game Border Configuration!", 1);
		exit(0);
	}
}

void	err_map_shape(void)
{
	ft_putendl_fd("Missaligned: Map not a Rectangle!", 1);
	exit(0);
}
