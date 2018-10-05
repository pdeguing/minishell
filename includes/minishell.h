/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:53:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/04 17:51:42 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <sys/wait.h>
# include <signal.h>
# define BLUE "\x1b[1;34m"
# define RED "\x1b[0;31m"
# define YELLOW "\x1b[0;33m"
# define WHITE "\x1b[1;37m"
# define RESET "\x1b[0m"

char	**g_env;

int		get_envlen(char **env);

int		replace_env(char *arg);
char	*get_varenv(char *name);

int		ft_echo(char **args);
int		ft_cd(char **args);
int		ft_env(char **args);
int		ft_setenv(char **args);
int		ft_unsetenv(char **args);
int		ft_exit(char **args);
int		ft_kwame(char **args);

void	handle_sig(int sig);
void	handle_childsig(int sig);

int		put_error(char *err, int errn);

int		launch_program(char **args);

char	*extension(char *arg, char c);

void	put_prompt(void);
char	*read_line(void);
char	**get_args(char *command);
char	**get_commands(char *line);
int		execute(char **args);

void	mini_loop(void);

void	init_env(char **environ);

#endif
