/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:52:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/28 15:45:57 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(void)
{
	char	*path;

	path = get_varenv("PATH");
	if (path == NULL)
		return (NULL);
	return (ft_strsplit(path, ':'));
}

int		try_path(char *path, char **args)
{
	path = ft_strffjoin(path, "/");
	path = ft_strffjoin(path, args[0]);
	if (execve(path, args, g_env) == -1)
		return (-1);
	ft_strdel(&path);
	return (0);
}

int		exec_allpath(char **args)
{
	int		i;
	char	**allpath;

	if (ft_strchr(args[0], '/'))
		return (execve(args[0], args, g_env));
	allpath = get_path();
	if (allpath == NULL)
		return (-1);
	i = 0;
	while (allpath[i] != NULL)
	{
		if (try_path(ft_strdup(allpath[i]), args) == 0)
			return (0);
		i++;
	}
	return (-1);
}

int		launch_program(char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (exec_allpath(args) == -1)
		{
			ft_printf("%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	if (pid > 0)
	{
		wait(&pid);
	}
	if (pid == -1)
	{
		ft_putendl_fd("error forking", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
