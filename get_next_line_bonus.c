/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:58:55 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/23 19:46:11 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_rest(char *str)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\n')
	{
		tmp = ft_strdup(str + i + 1);
		free(str);
		str = tmp;
		return (str);
	}
	str = NULL;
	return (str);
}

char	*get_line(char *str, int k)
{
	char	*new_buff;
	int		i;

	i = 0;
	new_buff = NULL;
	if (k == 0 && *str == '\0')
		return (free(str), NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\n')
	{
		new_buff = malloc((i + 2) * sizeof(char));
		if (!new_buff)
			return (NULL);
		ft_memcpy(new_buff, str, i);
		new_buff[i] = '\n';
		new_buff[i + 1] = '\0';
		return (new_buff);
	}
	new_buff = ft_strdup(str);
	return (free(str), str = NULL, new_buff);
}

char	*alloc_buffer(char *buffer)
{
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*alloc_rest(char *rest, char *buffer)
{
	if (!rest)
		rest = ft_strdup(buffer);
	else
		rest = ft_strjoin(rest, buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			k;
	static char	*rest[1024];
	char		*lines;

	k = 1;
	lines = NULL;
	buffer = NULL;
	buffer = alloc_buffer(buffer);
	if (rest[fd] && ft_strchr(rest[fd], '\n'))
		k = 0;
	while (k > 0)
	{
		k = read(fd, buffer, BUFFER_SIZE);
		if (k < 0)
			return (free(buffer), NULL);
		buffer[k] = '\0';
		rest[fd] = alloc_rest(rest[fd], buffer);
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	free(buffer);
	lines = get_line(rest[fd], k);
	rest[fd] = get_rest(rest[fd]);
	return (lines);
}
