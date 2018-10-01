/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_varenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:35:30 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/28 15:46:00 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_varenv(char *name)
{
	char	**var;

	var = ft_pstrcchr(g_env, name, '=');
	if (var == NULL)
		return (ft_strnew(1));
	return (*var + ft_strlen(name) + 1);
}
