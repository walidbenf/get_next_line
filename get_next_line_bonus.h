/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 20:39:57 by wben-far          #+#    #+#             */
/*   Updated: 2020/11/07 19:41:09 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			find_chr(char *str);
int			save_line(char **save, char **line, int i);
int			get_next_line(int fd, char **line);

#endif
