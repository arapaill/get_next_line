/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:39:34 by arapaill          #+#    #+#             */
/*   Updated: 2019/11/13 16:50:45 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 800
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int	    ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);

#endif