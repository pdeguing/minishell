# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 10:01:06 by pdeguing          #+#    #+#              #
#    Updated: 2018/10/04 17:52:39 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

NAME	= minishell

SRCS	= srcs/execute.c \
		  srcs/extension.c \
		  srcs/get_args.c \
		  srcs/get_commands.c \
		  srcs/get_envlen.c \
		  srcs/get_varenv.c \
		  srcs/init_env.c \
		  srcs/launch_program.c \
		  srcs/mini_loop.c \
		  srcs/minishell.c \
		  srcs/put_error.c \
		  srcs/put_prompt.c \
		  srcs/read_line.c \
		  srcs/builtins/ft_echo.c \
		  srcs/builtins/ft_cd.c \
		  srcs/builtins/ft_env.c \
		  srcs/builtins/ft_setenv.c \
		  srcs/builtins/ft_unsetenv.c \
		  srcs/builtins/ft_exit.c \
		  srcs/builtins/ft_kwame.c \
		  srcs/builtins/utils/replace_env.c

LIB		= -lft -L./libft/
LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) cmp

$(LIBFT):
	@ cd libft/ && make

cmp:
	@ gcc -o $(NAME) $(CFLAGS) $(SRCS) -Iincludes $(LIB)

clean:
	@ /bin/rm -f *.o
	@ cd libft/ && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ cd libft/ && make fclean

re: fclean all

.PHONY: clean fclean all re
