/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:34:33 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/23 01:23:41 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(ft_strlen((char *)src) + 1);
	if (!s)
		return (NULL);
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t l)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (l--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		max_len;
	char	*s;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return ((char *)s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	max_len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(max_len + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2);
	s[max_len] = '\0';
	free((char *)s1);
	return (s);
}
