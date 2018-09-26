/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:52:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/25 16:26:11 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
char	*get_path(char *arg)
{
	if (ft_strchr(PATH, arg) == 0)
		return (ft_strjoin(PATH, arg));
	return (ft_strdup(arg));
}
*/

int		launch_program(char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, NULL);
	}
	if (pid > 0)
	{
		wait(&pid);
	}
	if (pid < 0)
	{
	}
	return (0);
}
