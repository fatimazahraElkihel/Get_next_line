/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-kihe <fel-kihe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:01:52 by fel-kihe          #+#    #+#             */
/*   Updated: 2024/03/24 02:35:40 by fel-kihe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE  
#  define BUFFER_SIZE 1
# endif

# define OPEN 1024

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char **s1, char const *s2);
char	*get_next_line_bonus(int fd);

#endif
