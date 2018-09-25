/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:56:04 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/25 13:56:09 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_args(void)
{
	char	*line;
	char	**args;

	line = NULL;
	get_next_line(0, &line);
	args = ft_strsplit(line, ' ');
	return (args);
}
