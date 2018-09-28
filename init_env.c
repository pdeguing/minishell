/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:11:17 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/28 09:45:21 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **environ)
{
	int		i;
	int		len;

	len = get_envlen(environ);
	if (len == 0)
		return ;
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	if (g_env == NULL)
	{
		ft_putendl_fd("minishell: cannot allocate memory", 2);
		exit(EXIT_FAILURE);
	}
	g_env[len] = NULL;
	i = 0;
	while (environ[i] != NULL)
	{
		g_env[i] = ft_strdup(environ[i]);
		if (g_env[i] == NULL)
		{
			ft_putendl_fd("minishell: cannot allocate memory", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
