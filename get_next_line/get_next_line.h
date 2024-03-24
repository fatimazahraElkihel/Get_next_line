/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-kihe <fel-kihe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:30:18 by fel-kihe          #+#    #+#             */
/*   Updated: 2024/03/24 02:35:34 by fel-kihe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE  
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char **s1, char const *s2);
char	*get_next_line(int fd);
char	*allocate_initial_str(void);

#endif
