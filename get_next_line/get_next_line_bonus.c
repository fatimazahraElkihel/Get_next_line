/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-kihe <fel-kihe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:45:40 by fel-kihe          #+#    #+#             */
/*   Updated: 2024/03/24 02:29:59 by fel-kihe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	rest(char **str, int fd)
{
	char	*temp;
	char	*rest;

	temp = ft_strchr(str[fd], '\n');
	if (temp)
	{
		rest = NULL;
		temp++;
		rest = ft_strdup(temp);
		free(str[fd]);
		str[fd] = NULL;
		str[fd] = rest;
	}
	else
	{
		free(str[fd]);
		str[fd] = NULL;
	}
}

char	*return_line(char **str)
{
	int		len;
	int		i;
	char	*str1;

	len = 0;
	i = 0;
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	str1 = malloc((len + 1) * sizeof(char));
	if (!str1)
		return (NULL);
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
	{
		str1[i] = (*str)[i];
		i++;
	}
	if ((*str)[i] == '\n')
		str1[i++] = '\n';
	str1[i] = '\0';
	return (str1);
}

char	*allocate_initial_str(char *buff)
{
	char	*str;

	str = NULL;
	str = malloc(1 * sizeof(char));
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	str[0] = '\0';
	return (str);
}

char	*read_l(char **str, int fd)
{
	char	*line;

	line = NULL;
	if (*str[fd] != '\0')
	{
		line = return_line(&str[fd]);
		rest(str, fd);
	}
	return (line);
}

char	*get_next_line_bonus(int fd)
{
	char			*buff;
	static char		*str[OPEN];
	ssize_t			bytes_read;

	if (fd < 0)
		return (NULL);
	while (1)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		if (!str[fd])
			str[fd] = allocate_initial_str(buff);
		if (!str[fd])
			return (free(buff), NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0';
		str[fd] = ft_strjoin(&str[fd], buff);
		free(buff);
		if (ft_strchr(str[fd], '\n') || bytes_read == 0 || bytes_read == -1)
			break ;
	}
	buff = read_l(str, fd);
	return (buff);
}
