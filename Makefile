# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 09:14:19 by dtrigalo          #+#    #+#              #
#    Updated: 2019/01/15 14:48:27 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c					\
	   parse_conv.c					\
	   conv_functions_char.c		\
	   conv_functions_int.c			\
	   conv_functions_double.c		\
	   conv_functions_longdouble.c	\
	   conv_functions_percentage.c	\
	   conv_functions_binary.c		\
	   parse_accufield.c			\
	   accufield_functions.c		\
	   parse_flag.c					\
	   flag_functions.c				\
	   color_functions.c			\
	   exit_error.c					\
	   tools.c
OBJ = $(SRCS:.c=.o)
HEADERS = ft_printf.h libft/libft.h


all: $(NAME)
	@echo "\033[0;32mlibftprintf.a compiled successfully\033[0m"

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

libft/libft.a:
	@make -C ./libft

$(NAME): libft/libft.a $(OBJ)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
