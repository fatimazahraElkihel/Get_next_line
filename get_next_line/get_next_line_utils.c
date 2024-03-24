/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-kihe <fel-kihe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:30:11 by fel-kihe          #+#    #+#             */
/*   Updated: 2024/03/24 01:42:44 by fel-kihe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	str = NULL;
	if (*s1 != NULL || s2 != NULL)
	{
		len = ft_strlen(*s1) + ft_strlen(s2) + 1;
		str = (char *)malloc(len * sizeof(char));
		if (!str)
			return (NULL);
		while ((*s1)[i])
		{
			str[i] = (*s1)[i];
			i++;
		}
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		free(*s1);
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	(new = malloc(sizeof(char) * (len + 1)));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
