/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:56:04 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 13:08:14 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** I think there are vulnerabilities in this function because ft_strsplit()
** will segfault if you send NULL to it. Also get_next_line() seems to never
** set line to NULL, line is allocated by ft_strsub() that does not ensure
** returning a non-NULL pointer, so it could happen.
**
** This is something we will prevent right now by adding an extra condition
** to return NULL if line is NULL after get_next_line().
** But we will probably need to rework get_next_line() and ft_strsplit() so
** they have defined behaviour when receveiving/returning a NULL pointer.
**
** Actually we will probably need to implement our own strtok to handle more
** complicated input anyway.
*/

char	**get_args(char *command)
{
	char	**args;
	int		i;
	int		j;

	if (command == NULL)
		return (NULL);
	args = ft_strsplit(command, ' '); // SPLIT TABS TOO
	i = 0;
	while (args[i] != NULL)
	{
		if (args[i][0] == '~' && (args[i][1] == '/' || args[i][1] == '\0'))
			args[i] = extension(args[i], '~');
		while (ft_strchr(args[i], '$')) // CAN IMPROVE CONDITION
			args[i] = extension(args[i], '$');
		if (!ft_strlen(args[i]))
		{
			ft_strdel(&args[i]);
			j = i;
			while (args[j] != NULL)
			{
				args[j] = args[j + 1];
				j++;
			}
		}
		i++;
	}
	return (args);
}
