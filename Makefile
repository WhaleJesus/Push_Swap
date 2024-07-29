# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 15:19:11 by sklaps            #+#    #+#              #
#    Updated: 2024/07/29 20:59:59 by sklaps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			Push_Swap
LIBFT =			libft.a
SRC_FILES =		push_swap.c
SRC_DIR =		src2/
SRC =			$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ =			${SRC:.c=.o}
CC = 			cc
CFLAGS =		-Wall -Wextra -Werror
INCLUDE =		-I include
RM =			rm -rf

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) libft/$(LIBFT) -o $(NAME)

clean :
	@make clean -C libft
	${RM} $(OBJ)

fclean : clean
	@make fclean -C libft
	${RM} $(NAME)
	${RM} $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
