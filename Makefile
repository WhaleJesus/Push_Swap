# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 15:19:11 by sklaps            #+#    #+#              #
#    Updated: 2024/07/22 16:43:55 by sklaps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
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
	  src/stack_utils.c \
	  src/stack_utils22.c \
	  src/close.c \
	  src/main.c
EXT_LIB = libft/libft.a
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make all clean && cd ../ && -Llibft -lft $(CC) $(CFLAGS) $@ $^ $(EXT_LIB) 

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
