/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 20:39:50 by wben-far          #+#    #+#             */
/*   Updated: 2020/11/07 19:37:17 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int		find_chr(char *str)
{
	int		i;

	if (str != NULL && str[0])
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

int		save_line(char **save, char **line, int i)
{
	char	*temp;

	(*save)[i] = '\0';
	*line = ft_strdup(*save);
	temp = ft_strdup(*save + i + 1);
	free(*save);
	*save = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*call[4096];
	char			buffer[BUFFER_SIZE + 1];
	int				res;
	int				i;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || !(line) || (read(fd, buffer, 0)) < 0)
		return (-1);
	while ((res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		call[fd] = ft_strjoin(call[fd], buffer);
		if ((i = find_chr(call[fd])) >= 0)
			return (save_line(&call[fd], line, i));
	}
	if (call[fd] && (i = find_chr(call[fd])) >= 0)
		return (save_line(&call[fd], line, i));
	else if (call[fd])
	{
		*line = call[fd];
		call[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
