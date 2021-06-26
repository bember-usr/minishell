# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 00:56:05 by student           #+#    #+#              #
#    Updated: 2021/04/12 18:02:49 by rosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all bonus clean fclean re

NAME =		libft.a

SRC =		ft_putchar_fd.c ft_putendl_fd.c\
			ft_putnbr_fd.c ft_putstr_fd.c\
			ft_strclear.c ft_cntwords.c\
			ft_memccpy.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_isprint.c\
			ft_memmove.c ft_strjoin.c ft_strlcat.c\
			ft_strlcpy.c ft_strncmp.c ft_strnstr.c\
			ft_strrchr.c ft_tolower.c\
			ft_toupper.c ft_strmapi.c ft_putchar.c\
			ft_putendl.c ft_strcmpi.c ft_calloc.c\
			ft_memchr.c	ft_memcmp.c ft_memcpy.c\
			ft_memset.c ft_strchr.c ft_strdup.c\
			ft_strlen.c ft_strnew.c\
			ft_putstr.c ft_strrev.c ft_strcmp.c\
			ft_bzero.c \
			ft_atoi.c ft_sqrt.c \
			get_next_line.c get_next_line_utils.c

OBJ =		$(SRC:.c=.o)

BONUS_S =	ft_lstadd_front.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstlast.c\
			ft_lstsize.c ft_lstiter.c ft_lstnew.c\
		    ft_lstdelone.c ft_lstmap.c\

BONUS_O = $(BONUS_S:.c=.o)

#-c говорит не запускать линкер, потому что нет main
#-g порождает отладочную информацию в родном формате операционной системы
#включает использование дополнительной отладочной информации, 
#которую может использовать только GDB; 
#эта дополнительная отладочная информация делает работу отладки в GDB лучше, но может, 
#вероятно испортить работу других отладчиков, или помешать им прочитать программу.
FLAGS = -Wall -Wextra -Werror -c -g

FONT00 = \033[1m #жирный шрифт
FONT01 = \033[4m #подчеркивание
#COLOR12 = \033[6;35m - можно совмещать \033[6 - цвет шрифта ;35m - цвет фона
COLOR0 = \033[47m #серый цвет фона
FONT0 = \033[37m #серый цвет шрифта
COLOR1 = \033[46m #цвет морской волны фона		
FONT1 = \033[36m #цвет морской волны шрифта
COLOR2 = \033[45m #фиолетовый цвет фона
FONT2 = \033[35m #фиолетовый цвет шрифта
COLOR3 = \033[44m #синий цвет фона
FONT3 = \033[34m #синий цвет шрифта
COLOR4 = \033[43m #желтый цвет фона
FONT4 = \033[33m #желтый цвет шрифта
COLOR5 = \033[42m #зелёный цвет фона
FONT5 = \033[32m #зелёный цвет шрифта
COLOR6 = \033[41m #красный цвет фона
FONT6 = \033[31m #красный цвет шрифта
COLOR7 = \033[40m #чёрный цвет фона
FONT7 = \033[30m #чёрный цвет шрифта

%.o: %.c
	@echo "$(FONT5)gcc $(FLAGS) $< -o $@"
	@gcc $(FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(FONT2)ar rcs $(NAME) \t $(OBJ) \n"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(FONT1)$(FONT00)Libft successfully compiled"

bonus: $(BONUS_O)
	@echo "$(FONT2)ar rcs $(NAME) $(BONUS_O) \n"
	@ar rcs $(NAME) $(BONUS_O)
	@echo "$(FONT1)$(FONT00)Libft successfully compiled"

clean:
	@echo "$(FONT5)rm -f $(FONT6)$(OBJ) $(BONUS_O) \n"
	rm -f $(OBJ) $(BONUS_O)

fclean: clean
	@echo "$(FONT5)rm -f $(FONT6)$(NAME) \n"
	@rm -rf $(NAME)

re: fclean all
