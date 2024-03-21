/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:21:42 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/20 09:34:26 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack_list **a)
{
	t_stack_list	*list;

	list = *a;
	if (list != NULL)
	{
		while (list->next != NULL)
		{
			if (list->data > list->next->data)
				return (0);
			list = list->next;
		}
	}
	return (1);
}

t_stack_list	*ft_sort(t_stack_list **a, t_stack_list **b)
{
	int	length;

	length = lst_len(a);
	if (!a)
		return (NULL);
	if ((ft_is_sorted(a)))
		return (NULL);
	if (length == 2)
		write_inst_swap(a, b, "sa");
	else if (length == 3)
		sort_three(a, b);
	else if (length == 4)
		sort_four(a, b);
	else if (length > 4)
		sort_multi(a, b);
	return (*a);
}
