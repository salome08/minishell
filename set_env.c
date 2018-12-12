/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 16:13:25 by shazan            #+#    #+#             */
/*   Updated: 2015/05/05 16:13:48 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	aff_env(char **env)
{
	int i;

	i = 0;
	while (i < ft_env_len(env))
	{
		ft_putstr(env[i]);
		ft_putstr("\n");
		i++;
	}
}

char	**ft_setenv(char **env, char *str)
{
	char		**tab_line;
	int			i;
	int			env_len;
	char		*join;
	char		*join2;

	env_len = ft_env_len(env);
	i = 1;
	tab_line = str_to_wordtab(str);
	join = ft_strjoin(tab_line[1], "=");
	join2 = ft_strjoin(join, tab_line[2]);
	if (!(tab_line[1]))
		aff_env(env);
	else if (tab_line[3])
		ft_putendl("setenv : Too many arguments.");
	else if (!(is_in_env(env, join)))
		env = ft_setenv2(env, str, join, join2);
	else
		ft_strcpy(env[is_in_env(env, join)], join2);
	return (env);
}

char	**ft_setenv2(char **env, char *str, char *join, char *join2)
{
	int		env_len;
	char	**tab_line;

	env_len = ft_env_len(env);
	tab_line = str_to_wordtab(str);
	if (!(env = (char **)ft_realloc(env, sizeof(char *) * (env_len + 2))))
		return (NULL);
	if (!(env[env_len] = (char *)malloc(sizeof(char) *  \
		(count_letter(str) + 2))))
		return (NULL);
	if (tab_line[2])
		ft_strcpy(env[env_len], join2);
	else
		ft_strcpy(env[env_len], join);
	env[env_len + 1] = 0;
	free(join);
	return (env);
}

char	**ft_unsetenv(char **env, char **tab)
{
	char	*join;
	char	**env2;
	int		i;
	int		j;
	int		envlen;

	i = 0;
	join = ft_strjoin(tab[1], "=");
	j = is_in_env(env, join);
	envlen = ft_env_len(env);
	if (j == 0)
		return (env);
	if (!(env2 = (char **)malloc(sizeof(char *) * (envlen))))
		return (NULL);
	while (i < envlen - 1)
	{
		if (i < j)
			env2[i] = ft_strdup(env[i]);
		else if (i >= j)
			env2[i] = ft_strdup(env[i + 1]);
		i++;
	}
	env2[i] = 0;
	return (env2);
}

char	**get_path(char **env)
{
	char	**tab_path;
	char	*path;
	int		i;

	i = 0;
	path = ft_getenv(env, "PATH");
	tab_path = ft_strsplit(path, ':');
	return (tab_path);
}
