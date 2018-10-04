/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:01:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 11:56:36 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_cd(char **args)
{
	replace_env(ft_strfljoin("OLDPWD=", getcwd(NULL, 0)));
	if (args[0] == NULL)
	{
		if (chdir(get_varenv("HOME")) == -1)
		{
			ft_putendl_fd("cd: HOME not set", 2);
			return (-1);
		}
	}
	else if (chdir(args[0]) == -1)
	{
		ft_putendl_fd("cd: could not change directory", 2);
		return (-1);
	}
	replace_env(ft_strfljoin("PWD=", getcwd(NULL, 0)));
	return (0);
}
