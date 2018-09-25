/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:55:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/25 13:56:08 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*builtin_name[] = 
{
	"echo",
	"cd",
	"setenv",
	"unsetenv",
	"env",
	"exit"
};

int		(*builtin_func[])(char **) = 
{
	&ft_echo,
	&ft_cd,
	&ft_setenv,
	&ft_unsetenv,
	&ft_env,
	&ft_exit
};

int		execute(char **args)
{
	int		i;

	i = 0;
	while (i < builtin_nbr)
	{
		if (ft_strcmp(args[0], builtin_name[i] == 0)
				return (builtin_func[i](args + 1));
	}
	return (launch_program(args));
}
