# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 20:11:18 by juzoanya          #+#    #+#              #
#    Updated: 2022/10/25 19:05:51 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname -s)

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -ggdb3 $(INC)

PATH_SRC = ./src/
PATH_INC = ./inc/
PATH_GNL = ./gnl/
PATH_LIBFT = ./libft/
PATH_OBJS = ./objs/
INC = -I ./inc -I ./libft
ifeq ($(UNAME),Linux)
	PATH_MLX = ./mlx/mlx_linux/
else
	PATH_MLX = ./mlx/
endif

MLX = $(PATH_MLX)libmlx.a
LIBFT = $(PATH_LIBFT)libft.a

SRC = 	$(PATH_SRC)main.c \
		$(PATH_SRC)checks.c \
		$(PATH_SRC)game.c \
		$(PATH_SRC)move.c \
		$(PATH_SRC)maps.c \
		$(PATH_SRC)errors.c \
		$(PATH_SRC)utils.c \
		$(PATH_SRC)input.c \
		$(PATH_SRC)close_lin.c \
		$(PATH_SRC)helpers.c \
		$(PATH_SRC)destroy.c \
		$(PATH_GNL)get_next_line.c \
		$(PATH_GNL)get_next_line_utils.c \

SRCM = 	$(PATH_SRC)main.c \
		$(PATH_SRC)checks.c \
		$(PATH_SRC)game.c \
		$(PATH_SRC)move.c \
		$(PATH_SRC)maps.c \
		$(PATH_SRC)errors.c \
		$(PATH_SRC)utils.c \
		$(PATH_SRC)input.c \
		$(PATH_SRC)close_mac.c \
		$(PATH_SRC)helpers.c \
		$(PATH_SRC)destroy.c \
		$(PATH_GNL)get_next_line.c \
		$(PATH_GNL)get_next_line_utils.c \

ifeq ($(UNAME),Linux)
	OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))
else
	OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCM))
endif

MLXFLAGS = -I $(PATH_MLX) -L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --log-file=valgrind-out.txt

ARGS =	./maps/map.ber

all:	$(NAME)

$(NAME):	$(OBJS)
ifeq ($(UNAME),Linux)
	@make -C $(PATH_MLX)
	@make -C $(PATH_LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(CFLAGS) $(MLXFLAGS)
	@echo "$(NAME) created"
else
	@make -C $(PATH_MLX)
	@make -C $(PATH_LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(NAME) created"
endif

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
ifeq ($(UNAME),Linux)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) $(INC). -c $< -o $@
else
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
endif

clean:
	@make clean -C $(PATH_LIBFT)
	@rm -rf $(PATH_OBJS)
	@echo "OBJ Deleted!"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@rm -rf $(NAME)
	@echo "$(NAME) is Deleted!"

re:	fclean all

memcheck:	clean all
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)

norm:
	@norminette $(PATH_SRC) $(PATH_GNL) $(PATH_LIBFT) $(PATH_INC)

.PHONY:	all clean fclean re