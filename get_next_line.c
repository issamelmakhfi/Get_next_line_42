/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:58:55 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/23 19:52:01 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_rest(char *rest)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			break ;
		i++;
	}
	if (rest[i] == '\n')
	{
		tmp = ft_strdup(rest + i + 1);
		free(rest);
		rest = tmp;
		return (rest);
	}
	rest = NULL;
	return (rest);
}

static char	*get_line(char *rest, int k)
{
	char	*new_buff;
	int		i;

	i = 0;
	new_buff = NULL;
	if (k == 0 && *rest == '\0')
		return (free(rest), NULL);
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			break ;
		i++;
	}
	if (rest[i] == '\n')
	{
		new_buff = malloc((i + 2) * sizeof(char));
		if (!new_buff)
			return (NULL);
		ft_memcpy(new_buff, rest, i);
		new_buff[i] = '\n';
		new_buff[i + 1] = '\0';
		return (new_buff);
	}
	new_buff = ft_strdup(rest);
	return (free(rest), rest = NULL, new_buff);
}

static char	*alloc_buffer(char *buffer)
{
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char	*alloc_rest(char *rest, char *buffer)
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
	static char	*rest = NULL;
	char		*line;

	k = 1;
	line = NULL;
	buffer = NULL;
	buffer = alloc_buffer(buffer);
	if (rest && ft_strchr(rest, '\n'))
		k = 0;
	while (k > 0)
	{
		k = read(fd, buffer, BUFFER_SIZE);
		if (k < 0)
			return (free(buffer), NULL);
		buffer[k] = '\0';
		rest = alloc_rest(rest, buffer);
		if (ft_strchr(rest, '\n'))
			break ;
	}
	free(buffer);
	return (line = get_line(rest, k), rest = get_rest(rest), line);
}
