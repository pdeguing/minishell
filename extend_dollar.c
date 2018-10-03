/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:26:56 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/02 16:07:09 by pdeguing         ###   ########.fr       */
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
	while (arg[i] && (ft_isalnum(arg[i]) || arg[i] == '_'))
	{
		i++;
	}
	return (i);
}

char	*extension(char *arg, char symbol)
{
	char	*new;
	char	*var_name;
	char	*suffix;
	int		start;
	int		end;

	start = 1;
	end = 1;
	if (symbol == '$')
	{
		start = get_dstart(arg) + 1;
		end = get_dend(arg, start);
		var_name = ft_strsub(arg, start, end + 1);
	}
	else
		var_name = ft_strdup("HOME");
	new = ft_strsub(arg, 0, start - 1);
	suffix = ft_strsub(arg, end, ft_strlen(arg + end));
	new = ft_strffjoin(new, get_varenv(var_name));
	new = ft_strfjoin(new, suffix);
	ft_strdel(&arg);
	ft_strdel(&var_name);
	return (new);
}
