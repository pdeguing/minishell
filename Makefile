# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 10:01:06 by pdeguing          #+#    #+#              #
#    Updated: 2018/09/25 11:52:57 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

NAME	= minishell

SRCS	= *.c

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
