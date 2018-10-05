/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:55:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 17:20:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_builtin_name[] =
{
	"echo",
	"cd",
	"env",
	"setenv",
	"unsetenv",
	"exit",
	"kwame"
};

int		(*g_builtin_func[])(char **) =
{
	&ft_echo,
	&ft_cd,
	&ft_env,
	&ft_setenv,
	&ft_unsetenv,
	&ft_exit,
	&ft_kwame
};

int		builtin_nbr(void)
{
	return (sizeof(g_builtin_name) / sizeof(char *));
}

int		execute(char **args)
{
	int		i;

	if (args == NULL || args[0] == NULL)
		return (0);
	i = 0;
	if (ft_strchr(args[0], '/'))
		return (launch_program(args));
	while (i < builtin_nbr())
	{
		if (ft_strcmp(args[0], g_builtin_name[i]) == 0)
			return (g_builtin_func[i](args + 1));
		i++;
	}
	return (launch_program(args));
}
