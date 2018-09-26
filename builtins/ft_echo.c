/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:01:08 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/25 15:08:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_echo(char **args)
{
	int		i;


	i = 0;
	while (args[i])
	{
		ft_printf("%s", args[i]);
		i++;
		if (args[i])
			ft_printf(" ");
	}
	ft_printf("\n");
	return (0);
}