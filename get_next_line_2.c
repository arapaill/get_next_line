/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:38:33 by arapaill          #+#    #+#             */
/*   Updated: 2019/11/13 14:13:05 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char 	*cut(char *str, size_t size)
{
	char *array;

	array = ft_strdup(str);
	free(str);
	if(!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memcpy(str, array, size + 1);
	str[size] = '\0';
	free(array);
	array = NULL;
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char 		buf[BUFFER_SIZE + 1];
	static char	*rest;
	int			ret;

	if(rest != NULL)
	{
		*line = ft_strjoin(line, rest);
		*line = cut(*line, ft_strchr(*line, '\n'));
		if(ft_strchr(rest, '\n') != 0)
			rest = *ft_strdup(rest[ft_strchr(rest, '\n') + 1]);
		else
			return (1);
	}
	while (ret == read(fd, buf, BUFFER_SIZE) > 0)
		{
			buf[ret] = '\0';
			if((*line = ft_strjoin(*line, buf)) == 0);
				return (-1);
			if(ft_strchr(buf, '\n') != 0)
			{
				rest = *ft_strdup(&buf[ft_strchr(buf, '\n') + 1]);
				*line = cut(*line, ft_strchr(*line, '\n'));
				return (1);
			}
		}
}
