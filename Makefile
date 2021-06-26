# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 17:49:10 by rosfryd           #+#    #+#              #
#    Updated: 2021/04/12 18:03:26 by rosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFTPRINTF = ft_printf/libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =	minishell.c error.c ft_init.c mem.c execute.c do_commands.c env_utils.c mem1.c \
	parser/general_pars.c parser/ft_flags.c parser/ft_parser_utils_1.c \
	commands/_pwd.c commands/_print_env.c commands/ft_proc_utils_1.c commands/exit.c \
	commands/_export.c commands/unset.c commands/echo.c \

OBJ = $(SRC:.c=.o)

%.o : %.c
	gcc -c $< -o $@

all: $(NAME)

$(NAME): libftprintf $(OBJ)
	@ $(CC) $(FLAGS) $(SRC) $(LIBFTPRINTF) -o $(NAME)

libftprintf:
	@ $(MAKE) -C ft_printf

clean:
	$(MAKE) clean -C ft_printf/libft
	$(MAKE) clean -C ft_printf
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)
	$(MAKE) fclean -C ft_printf

re: fclean $(NAME)
