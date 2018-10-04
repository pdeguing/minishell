/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:08:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 11:48:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	commands_loop(char **commands)
{
	char	**args;
	int		i;

	if (commands == NULL)
		return ;
	i = 0;
	while (commands[i] != NULL)
	{
		args = get_args(commands[i]);
		execute(args);
		ft_pstrdel(args);
		i++;
	}
	ft_pstrdel(commands);
}

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		put_prompt();
		signal(SIGINT, handle_sig);
	}
}

void	handle_childsig(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		signal(SIGINT, handle_childsig);
	}
}

void	mini_loop(void)
{
	char	*line;

	signal(SIGINT, handle_sig);
	while (1)
	{
		put_prompt();
		line = read_line();
		commands_loop(get_commands(line));
		free(line);
	}
}


/*
** So we want to be able to run multiple commands separated by ';'
** A command is an array of pointers to strings so we want to be able to
** hold many of those array and send them to execute one by one.
** Do we create an array of array? In this case we need to know the number
** of commands before creating it.
** A linked list is more relevant then, but I guess the best is a stack
** in FIFO aka a Queue.
**
** But we can do less data management with a proper token algo actually.
** 1/ READ LINE
** 2/ GET TOKEN UNTIL ';' OR '\n'
** 3/ SPLIT TOKEN BY SPACE AND TABS => get us at the point we are at
** But we need to manage pipes and redirections later and extensions right now.
** So to add pipes and redi we will need extra step where we tokenize them.
** We can ignore that for now as our structure allows us to add it later.
** So how to manage extensions? We can read and replace in 2/ or do it after 3/.
** Also splitting by space won't be good enough to handle quotes.
**
** -> READ LINE
** -> FOR EACH COMMAND (';' || '\n')
**		-> STRSPLIT by /s && /t
**		-> FOR EACH ARG, IF EXTENSION -> REPLACE
**		-> SEND COMMAND TO EXECUTE
**		-> GET NEXT COMMAND
*/
