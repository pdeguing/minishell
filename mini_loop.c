/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:08:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/28 13:27:09 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	while (1)
	{
		put_prompt();
		line = read_line();
		args = get_args(line);
		status = execute(args);
		free(line);
		free(args);
	}
}
