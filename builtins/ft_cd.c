/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:01:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/25 16:32:36 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_cd(char **args)
{
	ft_printf("cd\n");
	if (args[0] == NULL)
		return (0); // TO REPLACE WITH HOME
	chdir(args[0]);
	return (0);
}
