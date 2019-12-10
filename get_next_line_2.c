/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:38:33 by arapaill          #+#    #+#             */
/*   Updated: 2019/11/25 16:25:07 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*cut(char *str, size_t size)
{
	char *array;

	array = ft_strdup(str);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memcpy(str, array, size + 1);
	str[size] = '\0';
	free(array);
	array = NULL;
	return (str);
}

int new_line(char **rest, char **line)
{
	*rest = ft_strdup(line[ft_strchr(*line, '\n')]);
	*line = cut(*line, ft_strchr(*line, '\n'));
	return (1);
}
int		read_line(char **line, int fd, char *buf, char **rest)
{
	int 	ret;

	while ((ret = read(fd, buf, BUFFER_SIZE) > 0))
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		if((ft_strchr(*line, '\n') != 0))
			return(new_line(&rest, line));
	}
	if (ft_strlen(*line) == 0 && ret == 0)
	{
		if (!(*line = malloc(sizeof(char) * 1)))
			return (-1);
		*line[0] = '\0';
		return (0);
	}
	return (0);
}


int		get_next_line(int fd, char **line)
{
	static char	*rest;
	char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if(ft_strlen(rest) != 0)
	{
		*line = ft_strjoin(*line, rest);
		if(ft_strchr(*line, '\n') != 0)
			return(new_line(&rest, line));
	}
	return (read_line(line, fd, buf, &rest));

}

int main()
{
	int fd;
	char **line;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, line))
	{
		printf(" main [%i] : %s \n",i, *line);
		free(*line);
		i++;
	}
	printf(" main [%i] : %s \n",i, *line);
	//system("leaks a.out");
	return (0);
}
