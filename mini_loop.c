/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:08:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/25 13:55:30 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_loop(void)
{
	char	**args;
	int		i;

	while (1)
	{
		put_prompt();
		args = get_args();
		i = 0;
		while (args[i])
		{
			ft_printf("%s\n", args[i]);
			i++;
		}
		execute(args);
	}
}
