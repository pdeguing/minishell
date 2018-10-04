/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 11:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 14:36:06 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_line(void)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) == -1)
	{
		ft_putendl_fd("could not read arguments", 2);
		exit(EXIT_FAILURE);
	}	
	if (line == NULL)
		ft_putchar('\n');
	return (line);
}
