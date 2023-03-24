/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 20:40:07 by wben-far          #+#    #+#             */
/*   Updated: 2020/11/07 19:48:44 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char		*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char				*str;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (!(s1) && !(s2))
		return (NULL);
	if (!(s1))
		return (ft_strdup(s2));
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
