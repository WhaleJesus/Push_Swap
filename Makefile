# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 15:19:11 by sklaps            #+#    #+#              #
#    Updated: 2024/07/11 15:24:38 by sklaps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
SRC = \
	  src/main.c \
	  src/moves.c \
	  src/moves2.c \
	  src/moves_utils.c \
	  src/moves_utils2.c \
	  src/split.c \
	  src/init_a_to_b.c \
	  src/init_b_to_a.c \
	  src/sort_stacks.c \
	  src/sort_three.c \
	  src/stack_init.c \
	  src/stack_utils.c
EXT_LIB = libft/libft.a
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make all clean && cd ../ && $(CC) $(CFLAGS)  $(OBJ) $(EXT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
