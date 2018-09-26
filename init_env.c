/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:11:17 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/26 11:15:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **environ)
{
	int		i;
	int		len;

	len = get_envlen(environ);
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	g_env[len] = NULL;
	i = 0;
	while (environ[i] != NULL)
	{
		g_env[i] = ft_strdup(environ[i]);
		i++;
	}
}
