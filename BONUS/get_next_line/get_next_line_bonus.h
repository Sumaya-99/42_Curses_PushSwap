/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:57:15 by suhelal           #+#    #+#             */
/*   Updated: 2024/01/25 09:41:07 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *str);

void	ft_bzero(void *s, size_t n);

char	*ft_strdup(const char *s1);

char	*ft_strchr(const char *s, int c);

#endif
