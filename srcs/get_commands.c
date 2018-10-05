/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:12:58 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 14:52:39 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_tab(char *c)
{
	if (*c == '\t')
		*c = ' ';
}

char	**get_commands(char *line)
{
	if (line == NULL || ft_strlen(line) == 0)
		return (NULL);
	ft_striter(line, replace_tab);
	return (ft_strsplit(line, ';'));
}
