/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:39:29 by arapaill          #+#    #+#             */
/*   Updated: 2019/11/12 12:31:16 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	n;

	n = ft_strlen(s);
	if (!(str = malloc((sizeof(char) * (n + 1)))))
		return (0);
	ft_strlcpy(str, s, n + 1);
	str[n] = '\0';
	return (str);
}

int		ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!dst && !src)
		return (NULL);
	if (dst == 0)
		return (dst);
	pdst = dst;
	psrc = (unsigned char *)(src);
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}


int		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*array;

	if (s2 == 0)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(array = malloc(sizeof(char ) * (len1 + len2 + 1))))
		return (NULL);
    if(s1 == NULL)
        ft_memcpy(array, s2, len2 + 1);
    ft_memcpy(array, s2, len1);
    ft_memcpy(&array[len1], s2, len2 + 1);
    free(s1);
	return (array);
}
