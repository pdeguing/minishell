/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:10:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/28 16:11:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		replace_env(char *arg)
{
	char	*tmp;
	char	**env;

	env = ft_pstrcchr(g_env, arg, '=');
	if (env == NULL)
		return (0);
	tmp = *env;
	*env = arg;
	free(tmp);
	return (1);
}
