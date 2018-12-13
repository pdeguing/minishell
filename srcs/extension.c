/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:43:13 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/14 15:11:10 by pdeguing         ###   ########.fr       */
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

char	*append_varenv(char *old, char *varenv)
{
	if (varenv == NULL)
		return (old);
	return (ft_strffjoin(old, varenv));
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
		var_name = ft_strsub(arg, start, end - 1);
	}
	else
		var_name = ft_strdup("HOME");
	new = ft_strsub(arg, 0, start - 1);
	suffix = ft_strsub(arg, end, ft_strlen(arg + end));
	new = append_varenv(new, get_varenv(var_name));
	new = ft_strfjoin(new, suffix);
	ft_strdel(&arg);
	ft_strdel(&var_name);
	return (new);
}

void	get_extension(char **parg)
{
	char	*sym;
	char	*arg;

	arg = *parg;
	if (arg[0] == '~' && (arg[1] == '/' || arg[1] == '\0'))
		*parg = extension(arg, '~');
	while ((sym = ft_strchr(arg, '$')) && ft_isalnum(*(sym + 1)))
		*parg = extension(arg, '$');
}
