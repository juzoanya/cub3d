/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:16:32 by juzoanya          #+#    #+#             */
/*   Updated: 2022/10/25 19:07:41 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_side(t_cube *game, t_pos *pos, int n)
{
	if (n == 0)
	{
		game->ply.side = n;
		pos->x++;
	}
	else if (n == 1)
	{
		game->ply.side = n;
		pos->y--;
	}
	else if (n == 2)
	{
		game->ply.side = n;
		pos->x--;
	}
	else if (n == 3)
	{
		game->ply.side = n;
		pos->y++;
	}
}

int	play_input(int keycode, t_cube *game)
{
	t_pos	pos;

	pos.x = game->ply.pos_x;
	pos.y = game->ply.pos_y;
	if (keycode == 0xff1b || keycode == 0x35)
		close_game(game);
	else if (keycode == 0x0041 || keycode == 0x0061 || keycode == 0x00)
		select_side(game, &pos, 1);
	else if (keycode == 0x0044 || keycode == 0x0064 || keycode == 0x02)
		select_side(game, &pos, 3);
	else if (keycode == 0x0057 || keycode == 0x0077 || keycode == 0x0D)
		select_side(game, &pos, 2);
	else if (keycode == 0x0053 || keycode == 0x0073 || keycode == 0x01)
		select_side(game, &pos, 0);
	else
		return (0);
	if (!(game->end) && !(game->ply.die))
		move_player(game, &pos);
	return (0);
}
