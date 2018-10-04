# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 10:01:06 by pdeguing          #+#    #+#              #
#    Updated: 2018/10/04 15:07:42 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

NAME	= minishell

SRCS	= *.c \
		  builtins/ft_echo.c \
		  builtins/ft_cd.c \
		  builtins/ft_env.c \
		  builtins/ft_setenv.c \
		  builtins/ft_unsetenv.c \
		  builtins/ft_exit.c \
		  builtins/ft_kwame.c \
		  builtins/utils/replace_env.c

LIB		= -lft -L./libft/
LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	gcc -o $(NAME) $(CFLAGS) $(SRCS) $(LIB)

$(LIBFT):
	cd libft/ && make

cmp:
	gcc -o $(NAME) $(CFLAGS) $(SRCS) $(LIB)

clean:
	/bin/rm -f *.o
	cd libft/ && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft/ && make fclean

re: fclean all

.PHONY: clean fclean all re
