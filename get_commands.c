/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:12:58 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 11:02:04 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_commands(char *line)
{
	if (line == NULL || ft_strlen(line) == 0)
		return (NULL);
//	ft_replace_char(line, '	', ' ');
	return (ft_strsplit(line, ';'));
}
