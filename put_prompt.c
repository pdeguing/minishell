/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:53:10 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 16:42:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_prompt(void)
{
	char	*pwd;
	char	*home;

	ft_printf(WHITE "minishell: " RESET);
	if ((pwd = get_varenv("PWD")) != NULL)
	{
		if ((home = get_varenv("HOME")) && ft_strstr(pwd, home))
			ft_printf("~%s ", pwd + ft_strlen(home));
		else
			ft_printf("%s ", pwd);
	}
	ft_printf(WHITE ">>> " RESET);
}
