/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_wordtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 18:47:09 by shazan            #+#    #+#             */
/*   Updated: 2015/04/21 20:40:06 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			i++;
		else
			return (i);
	}
	return (i);
}

int		count_word(char *str)
{
	int i;
	int nb_word;

	i = 0;
	nb_word = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t') && \
				str[i] != ' ' && str[i] != '\t')
			nb_word++;
		i++;
	}
	return (nb_word);
}

char	**str_to_wordtab(char *str)
{
	int		n;
	int		i;
	int		wd_len;
	int		nb_word;
	char	**tab;

	n = 0;
	i = 0;
	nb_word = count_word(str);
	tab = (char **)malloc(sizeof(*tab) * (nb_word + 1));
	while (n < nb_word)
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			i++;
		wd_len = word_len(&str[i]);
		tab[n] = malloc(sizeof(*tab) * (wd_len + 1));
		ft_strncpy(tab[n], &str[i], wd_len);
		tab[n][wd_len] = '\0';
		while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
			i++;
		n++;
	}
	tab[nb_word] = NULL;
	return (tab);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
}
