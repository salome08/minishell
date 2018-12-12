/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <shazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:18:55 by shazan            #+#    #+#             */
/*   Updated: 2015/05/07 16:27:24 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define A		0
# define INDICE	1
# define RET	2
# define BUF_SIZE 1024

int		get_next_line(int const fd, char **line);
void	stock_line(char *buf, char *line, int *i, int *var);
#endif
