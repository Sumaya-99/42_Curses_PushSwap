/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:59:33 by suhelal           #+#    #+#             */
/*   Updated: 2024/01/25 09:33:37 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_handle_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_handle_read(char **remain, char **ptr, char **buffer)
{
	char	*temp;

	temp = NULL;
	if (*remain)
	{
		*ptr = ft_strdup(*remain);
		ft_handle_free(remain);
	}
	if (!(*ptr))
		*ptr = ft_strdup(*buffer);
	else
	{
		temp = ft_strdup(*ptr);
		ft_handle_free(ptr);
		*ptr = ft_strjoin(temp, *buffer);
		ft_handle_free(&temp);
	}
	if (ft_strchr(*ptr, '\n'))
	{
		temp = ft_strchr(*ptr, '\n');
		*remain = ft_strdup(temp + 1);
		ft_bzero(temp + 1, ft_strlen(temp));
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		reading;
	char		*buffer;
	char		*ptr;
	static char	*remain[OPEN_MAX];

	reading = 1;
	ptr = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading < 0)
			return (ft_handle_free(&buffer), ft_handle_free(&remain[fd]), NULL);
		buffer[reading] = '\0';
		if (ft_handle_read(&remain[fd], &ptr, &buffer))
			break ;
	}
	ft_handle_free(&buffer);
	if (ptr && *ptr == '\0')
		ft_handle_free(&ptr);
	return (ptr);
}
