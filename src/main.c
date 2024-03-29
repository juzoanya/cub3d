/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:27:13 by juzoanya          #+#    #+#             */
/*   Updated: 2022/10/25 21:55:01 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_close(t_cube *game)
{
	close_game(game);
	return (0);
}

void	run_cube(t_cube game)
{
	game_init(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		perror();
	game->win = mlx_new_window();
	if (!game->win)
		perror();
}

int	main(int argc, char *argv[])
{
	t_cube	game;

	if (argc < 2)
	{
		ft_putendl_fd("Pass the location to Game map!", 1);
		exit(0);
	}
	game->mlx = mlx_init();
	map_init(&game, argv);
	run_cube(&game);
	game->win = mlx_new_window(game->mlx, game->scrn.height, game->scrn.width, "Cub3D");
	game->img.ptr = mlx_new_image(game->mlx, game->scrn.width, game->scrn.height);
	//game->img.addr = mlx_get_data_addr();
	mlx_hook(game->win, 17, 0L, game_close, (void *)game);
	mlx_hook(game->win, 2, 1L << 0, play_input, (void *)game);
	mlx_loop_hook(game->mlx, game_play, game);
	mlx_loop(game->mlx);
}
	exit(0);
}
