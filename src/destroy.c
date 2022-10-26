/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:58:28 by juzoanya          #+#    #+#             */
/*   Updated: 2022/10/25 19:07:13 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_player_image(t_cube *game)
{
	if (game->player[0].img)
		mlx_destroy_image(game->mlx, game->player[0].img);
	if (game->player[1].img)
		mlx_destroy_image(game->mlx, game->player[1].img);
	if (game->player[2].img)
		mlx_destroy_image(game->mlx, game->player[2].img);
	if (game->player[3].img)
		mlx_destroy_image(game->mlx, game->player[3].img);
	if (game->player[4].img)
		mlx_destroy_image(game->mlx, game->player[4].img);
}

void	destroy_snag_image(t_cube *game)
{
	if (game->snag[0].img)
		mlx_destroy_image(game->mlx, game->snag[0].img);
	if (game->snag[1].img)
		mlx_destroy_image(game->mlx, game->snag[1].img);
	if (game->snag[2].img)
		mlx_destroy_image(game->mlx, game->snag[2].img);
	if (game->snag[3].img)
		mlx_destroy_image(game->mlx, game->snag[3].img);
	if (game->snag[4].img)
		mlx_destroy_image(game->mlx, game->snag[4].img);
}

void	destroy_image(t_cube *game)
{
	destroy_player_image(game);
	destroy_snag_image(game);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->space.img)
		mlx_destroy_image(game->mlx, game->space.img);
	if (game->coins.img)
		mlx_destroy_image(game->mlx, game->coins.img);
	if (game->exit[0].img)
		mlx_destroy_image(game->mlx, game->exit[0].img);
	if (game->exit[1].img)
		mlx_destroy_image(game->mlx, game->exit[1].img);
}

void	destroy_map(t_cube *game)
{
	int	i;

	i = 0;
	while (i < game->map.row)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}
