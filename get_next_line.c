/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:39:32 by arapaill          #+#    #+#             */
/*   Updated: 2019/11/12 12:31:15 by arapaill         ###   ########.fr       */
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

int     get_next_line(int fd, char **line)
{
	char 		buf[BUFFER_SIZE + 1];
	int			ret;
	static char *rest;

	if (fd < 0 || line == NULL)
	return (-1);
	if(rest[fd] != NULL)
	{
		*line = ft_strjoin(*line, rest);
		*rest = NULL;
	}
	while (ret = read(fd, buf, BUFFER_SIZE))
		{
			buf[ret] = '\0';
			*line = ft_strjoin(*line, buf);
			if(ft_strchr(buf, '\n') != 0)
			{
				rest[fd] = ft_strdup(buf[ft_strchr(buf, '\n') + 1]);
				*line = cut(*line, strchr(*line, '\n'));
				return (1);
			}
		}
	return(0);
}
