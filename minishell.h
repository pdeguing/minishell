/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:53:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/26 15:41:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/includes/libft.h"
# include <sys/wait.h>
# define BLUE "\x1b[1;34m"
# define RESET "\x1b[0m"

char	**g_env;

int		get_envlen(char **env);

int		ft_echo(char **args);
int		ft_cd(char **args);
int		ft_env(char **args);
int		ft_setenv(char **args);
int		ft_unsetenv(char **args);
int		ft_exit(char **args);

int		launch_program(char **args);

void	put_prompt(void);
char	**get_args(void);
int		execute(char **args);

void	mini_loop(void);

void	init_env(char **environ);

#endif
