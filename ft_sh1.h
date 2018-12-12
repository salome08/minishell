/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 17:14:39 by shazan            #+#    #+#             */
/*   Updated: 2016/01/12 15:49:19 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct	s_path
{
	char **tab;
	char *path;
	char *pwd;
	char *oldpwd;
	char *shlvl;
}				t_path;

void			put_error(char *tab);
char			**change_env(char **env, char *pwd, char *oldpwd);
char			**main_loop(char **env, char **env2, char *line);
char			**ft_setenv2(char **env, char *str, char *join, char *join2);
char			**ft_change_dir(char **env, char **tab);
char			**ft_unsetenv(char **env, char **tab);
int				is_in_env(char **env, char *var);
int				ft_env_len(char **env);
char			**copy_env(char **env);
int				count_letter(char *str);
char			**ft_setenv(char **env, char *str);
char			**get_path(char **env);
void			aff_env(char **env);
char			**str_to_wordtab(char *str);
void			aff_tab(char **tab);
char			*ft_getenv(char **env, char *elem);
void			free_tab(char **tab);

#endif
