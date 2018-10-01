/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:26:56 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/01 12:57:58 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_dstart(char *arg)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '$')
		i++;
	return (i);
}

int		get_dend(char *arg, int dstart)
{
	int		i;

	i = dstart;
	while (arg[i] && ft_isalnum(arg[i]))
	{
		i++;
	}
	return (i);
}

char	*extend_dollar(char *arg)
{
	char	*new;
	char	*var_name;
	char	*suffix;
	int		dstart;
	int		dend;

	dstart = get_dstart(arg) + 1;
	dend = get_dend(arg, dstart); // WE MUST BE SURE THE VAR NAME ENDS WHEN IT SHOULD, CHECK EXACT CONDITION
	new = ft_strsub(arg, 0, dstart - 1);
	var_name = ft_strsub(arg, dstart, dend + 1);
	suffix = ft_strsub(arg, dend + 1, ft_strlen(arg + dend + 1));
	ft_strdel(&arg);
	new = ft_strffjoin(new, get_varenv(var_name)); // VARENV CAN RETURN NULL BUT STRJOIN BREAK IF YOU SEND NULL
	new = ft_strfjoin(new, suffix);
	return (new);
}
