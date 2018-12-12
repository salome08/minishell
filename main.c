/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 16:57:51 by shazan            #+#    #+#             */
/*   Updated: 2015/05/04 10:13:43 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		execute_banane(char **env, char *line)
{
	char	**str_tab;
	char	**tab_path;
	int		i;
	pid_t	child;

	i = 0;
	str_tab = str_to_wordtab(line);
	tab_path = get_path(env);
	child = fork();
	if (child == 0)
	{
		if (execve(str_tab[0], str_tab, env) == -1)
			while (tab_path && tab_path[i])
				execve(ft_strjoin(ft_strjoin(tab_path[i++], "/"), \
					str_tab[0]), str_tab, env);
		put_error(str_tab[0]);
		exit(0);
	}
	else
		waitpid(child, NULL, 0);
}

int			main(int ac, char **av, char **env)
{
	char		*line;
	char		**env2;

	(void)ac;
	(void)av;
	env2 = copy_env(env);
	line = NULL;
	while (42)
		env2 = main_loop(env, env2, line);
	return (0);
}

char		**main_loop(char **env, char **env2, char *line)
{
	char		**tab;

	(void)env;
	ft_putstr("$>");
	if (get_next_line(0, &line) <= 0)
		exit(0);
	tab = str_to_wordtab(line);
	if (!(tab[0]))
		;
	else if (!(ft_strcmp(tab[0], "cd")))
		env2 = ft_change_dir(env2, tab);
	else if (!(ft_strcmp(line, "env")))
		aff_env(env2);
	else if (ft_strcmp(line, "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (!(ft_strcmp(tab[0], "setenv")))
		env2 = ft_setenv(env2, line);
	else if (!(ft_strcmp(tab[0], "unsetenv")))
		env2 = ft_unsetenv(env2, tab);
	else
		execute_banane(env2, line);
	return (env2);
}

char		**ft_change_dir(char **env, char **tab)
{
	char *buf;
	char *oldpwd;
	char *pwd;

	buf = (char *)malloc(sizeof(char) * 255);
	oldpwd = (char *)malloc(sizeof(char) * 255);
	getcwd(buf, 255);
	ft_strcpy(oldpwd, buf);
	if (tab[1])
	{
		if (chdir(tab[1]) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(tab[1]);
			return (env);
		}
	}
	else if (chdir(ft_getenv(env, "HOME")) == -1)
		ft_putstr("HOME non set\n");
	pwd = getcwd(buf, 255);
	env = change_env(env, pwd, oldpwd);
	return (env);
}

int			count_letter(char *str)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			nb++;
			i++;
		}
	}
	return (nb - 6);
}
