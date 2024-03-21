/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:30:59 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/15 15:15:46 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argument_lengths(int c, char **av)
{
	int	total_length;
	int	count;

	total_length = 0;
	count = 1;
	while (count < c)
	{
		total_length += strlen(av[count]);
		count++;
	}
	return (total_length);
}

char	*join_arguments_with_spaces(int c, char **av, int total_length)
{
	char	*joined_str;
	int		count;
	char	*current;
	char	*temp;

	joined_str = (char *)malloc(sizeof(char) * (total_length + 1));
	if (!joined_str)
		return (NULL);
	count = 1;
	current = joined_str;
	while (count < c)
	{
		temp = av[count];
		while (*temp != '\0')
			*current++ = *temp++;
		if (count < c - 1)
		{
			*current = ' ';
			current++;
		}
		count++;
	}
	*current = '\0';
	return (joined_str);
}

char	*join_arg(int c, char **av)
{
	int		total_length;
	char	*joined_str;

	total_length = argument_lengths(c, av);
	total_length += (c - 2);
	joined_str = join_arguments_with_spaces(c, av, total_length);
	if (*joined_str == '\0')
		free_str(joined_str);
	return (joined_str);
}
