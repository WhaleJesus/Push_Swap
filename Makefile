# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaps <sklaps@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 15:12:46 by sklaps            #+#    #+#              #
#    Updated: 2025/06/11 15:13:04 by sklaps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -g -Wall -Wextra -Werror -Iinclude -Ilibft

SRCDIR		= src
OBJDIR		= objs
LIBFTDIR	= libft
LIBFT		= $(LIBFTDIR)/libft.a

SRCFILES	= input.c \
			  exit.c \
			  init_stack.c \
			  swap.c \
			  push.c \
			  rotate.c \
			  algo.c \
			  turk_algo.c \
			  turk_algo_helpers.c \
			  turk_algo_helpers_2.c \
			  turk_algo_push_more_than_25_lines.c \
			  print_list.c \
			  algo_helpers.c

MAINFILE	= main.c

SRC			= $(addprefix $(SRCDIR)/, $(SRCFILES))
MAIN		= $(SRCDIR)/$(MAINFILE)

OBJ			= $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))
MAINOBJ		= $(OBJDIR)/$(MAINFILE:.c=.o)

RM			= rm -f
MKDIR		= mkdir -p

# Colors (optional)
GREEN		= \033[0;32m
YELLOW		= \033[38;2;255;255;0m
NEON		= \033[38;5;198m 
NC			= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MAINOBJ)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) $(MAINOBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✔️ Build successful: $(NAME)$(nc)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(RM) $(OBJ)
	$(RM) $(MAINOBJ)
	@echo "$(GREEN)clean done$(NC)"

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)
	@echo "$(GREEN)fclean done$(NC)"

re: fclean all

.PHONY: all clean fclean re

