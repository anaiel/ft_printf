# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:24:35 by dtrigalo          #+#    #+#              #
#    Updated: 2018/12/23 19:01:18 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
OBJ = 		ft_itoa_base.o	\
			ft_atoi.o		\
			ft_bzero.o		\
			ft_isalnum.o	\
			ft_isascii.o	\
			ft_isdigit.o	\
			ft_isalpha.o	\
			ft_lstdel.o		\
			ft_isprint.o	\
			ft_lstdelone.o	\
			ft_lstiter.o	\
			ft_lstmap.o		\
			ft_lstnew.o		\
			ft_itoa.o		\
			ft_memalloc.o	\
			ft_memccpy.o	\
			ft_memcmp.o		\
			ft_memdel.o		\
			ft_memcpy.o		\
			ft_lstadd.o		\
			ft_memmove.o	\
			ft_putchar.o	\
			ft_memset.o		\
			ft_putchar_fd.o	\
			ft_memchr.o		\
			ft_putendl_fd.o	\
			ft_putendl.o	\
			ft_putnbr.o		\
			ft_putnbr_fd.o	\
			ft_putstr_fd.o	\
			ft_putstr.o		\
			ft_stpcpy.o		\
			ft_strclr.o		\
			ft_strcat.o		\
			ft_strchr.o		\
			ft_strdel.o		\
			ft_strcmp.o		\
			ft_strcpy.o		\
			ft_strequ.o		\
			ft_striter.o	\
			ft_striteri.o	\
			ft_strdup.o		\
			ft_strlen.o		\
			ft_strjoin.o	\
			ft_strmap.o		\
			ft_strmapi.o	\
			ft_strlcat.o	\
			ft_strncat.o	\
			ft_strncmp.o	\
			ft_strnequ.o	\
			ft_strnew.o		\
			ft_strncpy.o	\
			ft_strnstr.o	\
			ft_strrchr.o	\
			ft_strsub.o		\
			ft_strstr.o		\
			ft_strtrim.o	\
			ft_tolower.o	\
			ft_toupper.o	\
			ft_strsplit.o	\
			ft_isspace.o	\
			ft_isupper.o	\
			ft_islower.o	\
			ft_is_prime.o	\
			ft_power.o		\
			ft_fact.o		\
			ft_doubletoa.o	\
			ft_llitoa.o		\
			ft_litoa.o		\
			ft_putwchar.o	\
			ft_wchar_to_bytes.o \
			ft_double_power.o	\
			ft_ldouble_power.o
SRCS = $(OBJ:.o=.c)
HEADERS = libft.h

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $^

all: $(NAME)

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
