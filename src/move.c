/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:14:49 by juzoanya          #+#    #+#             */
/*   Updated: 2022/10/25 19:08:00 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_moves_cli(t_cube *game)
{
	ft_putstr_fd("moves = ", 1);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
}

static void	last_tile_move(t_cube *game, t_pos *pos, int x, int y)
{
	if (game->exit_state == 1 && game->map.map[pos->x][pos->y] == 'E')
	{
		game->map.map[x][y] = '0';
		game->moves++;
		print_moves_cli(game);
	}
}

static void	game_end_state(t_cube *game)
{
	if (!player_active(game))
		game->end = 1;
}

void	move_player(t_cube *game, t_pos *pos)
{
	int	x;
	int	y;

	x = game->ply.pos_x;
	y = game->ply.pos_y;
	if (game->map.map[pos->x][pos->y] != '1')
	{
		if (game->map.map[pos->x][pos->y] != 'E')
		{
			if (game->map.map[pos->x][pos->y] == 'C')
				game->gems--;
			if (game->map.map[pos->x][pos->y] == 'S')
				game->ply.die = 1;
			if (game->gems == 0)
				game->exit_state = 1;
			game->map.map[x][y] = '0';
			game->map.map[pos->x][pos->y] = 'P';
			game->moves++;
			game->ply.pos_x = pos->x;
			game->ply.pos_y = pos->y;
			print_moves_cli(game);
		}
		last_tile_move(game, pos, x, y);
	}
	game_end_state(game);
}

int	player_active(t_cube *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.row)
	{
		y = 0;
		while (y < game->map.col)
		{
			if (game->map.map[x][y] == 'P')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
