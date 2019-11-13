/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:39:32 by arapaill          #+#    #+#             */
/*   Updated: 2019/11/13 16:51:36 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

int if_rest(char *rest, char **line)
{
	char *rest_cp;

	printf("rest :%s \n",rest);
	rest_cp = ft_strdup(rest);
	*line = ft_strjoin(*line, rest);
	*line = cut(*line, ft_strchr(*line, '\n'));
	if(ft_strchr(rest, '\n') != 0)
	{
		free(rest);
		*rest = *ft_strdup(&rest_cp[ft_strchr(rest_cp, '\n') + 1]);
		free(rest_cp);
		return (1);
	}
	else
	{	
		free (rest_cp);	
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	char 		buf[BUFFER_SIZE + 1];
	static char	*rest;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ret = 0;
	if(rest != NULL)
		if(if_rest(rest, line) == 1)
			return(1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = '\0';
			if((*line = ft_strjoin(*line, buf)) == 0)
				return (-1);
				printf("join : %s \n", *line);
			if(ft_strchr(buf, '\n') != 0)
			{
				rest = ft_strdup(&buf[ft_strchr(buf, '\n') + 1]);
				*line = cut(*line, ft_strchr(*line, '\n'));
				printf("cut : %s \n", *line);
				return (1);
			}
		}
	if (ft_strlen(*line) == 0 && ret == 0)
	{
		if (!(*line = malloc(sizeof(char) * 1)))
			return (-1);
		*line[0] = '\0';
		return (0);
	}
	return (ret);
}

int main()
{
	int fd;
	char **line;
	int i;

	i = 2;
	fd = open("test.txt", O_RDONLY);
	while (i > 0)
	{
		get_next_line(fd, &*line);
		printf(" main :%s \n", *line);
		i--;
	}
	
	
}
