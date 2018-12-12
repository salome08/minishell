/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 16:10:55 by shazan            #+#    #+#             */
/*   Updated: 2015/05/05 16:11:12 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		*ft_getenv(char **env, char *elem)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!(ft_strncmp(env[i], elem, ft_strlen(elem))))
			return (env[i] + ft_strlen(elem) + 1);
		i++;
	}
	return (0);
}

int			ft_env_len(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char		**copy_env(char **env)
{
	char	**env2;
	int		i;
	int		envlen;

	i = 0;
	envlen = ft_env_len(env);
	if (!(env2 = (char **)malloc(sizeof(char *) * (envlen + 1))))
		return (NULL);
	while (i < envlen)
	{
		env2[i] = ft_strdup(env[i]);
		i++;
	}
	env2[i] = 0;
	return (env2);
}

int			is_in_env(char **env, char *var)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!(ft_strncmp(env[i], var, ft_strlen(var))))
		{
			return (i);
		}
		i++;
	}
	return (0);
}
