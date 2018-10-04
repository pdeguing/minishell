/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:03:00 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 12:34:43 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_env(char *arg)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	len = get_envlen(g_env) - 1;
	tmp = g_env;
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	g_env[len] = NULL;
	i = 0;
	j = 0;
	while (tmp[i] != NULL && j < len)
	{
		if (ft_strccmp(tmp[i], arg, '='))
		{
			g_env[j] = ft_strdup(tmp[i]);
			j++;
		}
		i++;
	}
	ft_pstrdel(tmp);
}

int		ft_unsetenv(char **args)
{
	int		i;

	i = -1;
	while (args[++i] != NULL)
	{
		if (ft_strchr(args[i], '=') || ft_strchr(args[i], '*'))
		{
			ft_printf("unsetenv: %s: not a valid identifier\n", args[i]);
			continue ;
		}
		if (ft_pstrcchr(g_env, args[i], '=') != NULL)
			remove_env(args[i]);
	}
	return (0);
}
