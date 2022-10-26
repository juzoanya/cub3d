/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:28:37 by juzoanya          #+#    #+#             */
/*   Updated: 2022/10/25 21:50:05 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __linux__
#  define OS_LINUX 1
#  include "../mlx/mlx_linux/mlx.h"
# elif __APPLE__
#  define OS_LINUX 0
#  include "../mlx/mlx.h"
# endif

# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_dir
{
	int	x;
	int	y;
}				t_dir;

typedef struct s_plane
{
	int	x;
	int	y;
}				t_plane;

typedef struct s_win
{
	int	width;
	int	height;
}				t_win;

typedef struct s_map
{
	char	**map;
	int		col;
	int		row;
}				t_map;

typedef struct s_img
{
	char	*ptr;
	char	*addr;
}				t_img;

typedef struct s_player
{
	void	*player;
	t_pos	pos;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	ply;
	t_win		scrn;
	t_dir		dir;
	t_plane		plane;
	t_img		img;
	int			end;
}				t_game;

#endif