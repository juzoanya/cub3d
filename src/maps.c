/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:43:40 by juzoanya          #+#    #+#             */
/*   Updated: 2022/10/25 20:53:43 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	push_to_array(t_cube *game, int fd)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	x = 0;
	while (x < game->map.row)
	{
		i = 0;
		y = 0;
		str = get_next_line(fd);
		while (y < game->map.col)
		{
			game->map.map[x][y] = str[i];
			i++;
			y++;
		}
		free(str);
		x++;
	}
}

void	set_player_pos(t_cube *game)
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
			{
				game->ply.pos.x = x;
				game->ply.pos.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	map_init(t_cube *game, char **argv)
{
	int		fd;
	int		i;

	game->gems = 0;
	game->map.row = get_line_count(argv);
	row_len(game, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_file_open();
	game->map.map = (char **)malloc(sizeof(game->map.map) * game->map.row);
	i = 0;
	while (i < game->map.row)
	{
		game->map.map[i] = (char *)malloc(sizeof(game->map.map[i])
				* game->map.col - 1);
		i++;
	}
	push_to_array(game, fd);
	if (close(fd) == -1)
		err_file_close();
	check_map_char(game);
	check_map_shape(game, argv);
	set_player_pos(game);
}
