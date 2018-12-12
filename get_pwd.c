/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 11:51:25 by shazan            #+#    #+#             */
/*   Updated: 2015/05/07 11:51:35 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		**change_env(char **env, char *pwd, char *oldpwd)
{
	int i;

	i = is_in_env(env, "PWD=");
	env[i] = ft_strjoin("PWD=", pwd);
	i = is_in_env(env, "OLDPWD");
	env[i] = ft_strjoin("OLDPWD=", oldpwd);
	return (env);
}

void		put_error(char *tab)
{
	ft_putstr("zsh: command not found: ");
	ft_putstr(tab);
	ft_putchar('\n');
}
