/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:39:34 by arapaill          #+#    #+#             */
/*   Updated: 2019/11/12 12:32:20 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4098

#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int	    ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);


#endif