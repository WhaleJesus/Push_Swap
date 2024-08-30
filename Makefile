# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 15:19:11 by sklaps            #+#    #+#              #
#    Updated: 2024/08/30 19:23:24 by sklaps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			Push_Swap
LIBFT =			libft.a
PS_FILES =		push_swap.c \
				input.c \
				stack_utils.c \
				init_stack.c\
				errors.c \
				ab.c \
				ba.c
COM_FILES =		rev_rotate.c \
				rotate.c \
				swap.c \
				push.c \
				sort.c \
				sort_three.c
PS_DIR =		push_swap/
COM_DIR =		commands/
SRC_DIR =		src/
SRCC =			$(addprefix $(COM_DIR), $(COM_FILES))
SRCPS =			$(addprefix $(PS_DIR), $(PS_FILES))
SRC =			$(addprefix $(SRC_DIR), $(SRCC)) $(addprefix $(SRC_DIR), $(SRCPS))
OBJ =			${SRC:.c=.o}
CC = 			cc
CFLAGS =		-Wall -Wextra -Werror -g
INCLUDE =		-I include
RM =			rm -rf

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) libft/$(LIBFT) -o $(NAME)

clean :
	@make clean -C libft
	${RM} $(OBJ)

fclean : clean
	@make fclean -C libft
	${RM} $(NAME)
	${RM} $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
