/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-kihe <fel-kihe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:30:15 by fel-kihe          #+#    #+#             */
/*   Updated: 2024/03/24 06:49:29 by fel-kihe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    rest(char **str)
{
        char    *temp;
        char    *rest;

	temp = NULL;
	rest = NULL;
        temp = ft_strchr(*str, '\n');
        if (temp)
        {
                temp++;
                rest = ft_strdup(temp);
                free(*str);
                *str = NULL;
                *str = rest;
        }
        else
        {
                free(*str);
                *str = NULL;
        }
}

char    return_line(char str)
{
    int        len;
    int        i;
    char    str1;

    len = 0;
    i = 0;
    while (str[len] && str[len] != '\n')
        len++;
    if(str[len] == '\n')
        len++;
    str1 = malloc((len + 1) sizeof(char));
    if (!str1)
        return (NULL);
    i = 0;
    while (str[i] != '\n' && str[i] != '\0')
    {
        str1[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
        str1[i++] = '\n';
    str1[i] = '\0';
    return (str1);
}

char	*allocate_initial_str(void)
{
	char	*str;

	str = malloc(1 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char    *read_l(char str)
{
    char    *line;

    line = NULL;
    if (str != '\0')
    {
        line = return_line(str);
        rest(str);
    }
    else
    {
        free (str);
        *str = NULL;
    }
        return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (1)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		if (!str)
			str = allocate_initial_str();
		if (!str)
			return (free(buff), NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if(bytes_read == -1)
			return (free(buff), free(str), NULL);
		buff[bytes_read] = '\0';
		str = ft_strjoin(&str, buff);
		free(buff);
		if (ft_strchr(str, '\n') || (bytes_read == 0))
			break ;
	}
	buff = read_l(&str);
	return (buff);
}

int main()
{
	int fd;
	fd = open("file.txt", O_CREAT|O_RDONLY , 0777);
	char *str;
	do
	{
		str =  get_next_line(fd);
		printf("%s",str);
		free(str);
	}while(str);
	close(fd);
}
