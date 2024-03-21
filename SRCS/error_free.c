/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:05:46 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 13:23:41 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_str(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free (spl[i]);
		i++;
	}
	free (spl);
}

void	ft_free_list(t_stack_list **list)
{
	t_stack_list	*current;

	current = *list;
	while (current != NULL)
	{
		*list = current->next;
		free (current);
		current = *list;
	}
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_free_list_str(t_stack_list **list, char **spl)
{
	t_stack_list	*current;
	int				i;

	current = *list;
	i = 0;
	while (spl[i])
	{
		free (spl[i]);
		i++;
	}
	free (spl);
	while (current != NULL)
	{
		*list = current->next;
		free (current);
		current = *list;
	}
	write(2, "Error\n", 6);
	exit (1);
}

void	last_free_list(t_stack_list **list)
{
	t_stack_list	*current;

	current = *list;
	while (current != NULL)
	{
		*list = current->next;
		free (current);
		current = *list;
	}
}

void	free_str(char *str)
{
	if (str != NULL)
	{
		free (str);
		str = NULL;
	}
}
