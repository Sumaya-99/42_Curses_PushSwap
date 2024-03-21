/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:20:17 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 09:20:19 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_min_b(t_stack_list **b, t_target_node *target)
{
	t_stack_list	*temp;
	int				max_value;
	int				min_value;

	if (*b == NULL)
		return ;
	temp = *b;
	max_value = temp->data;
	min_value = temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data > max_value)
			max_value = temp->data;
		else if (min_value > temp->data)
			min_value = temp->data;
	}
	target->min_stack_b = min_value;
	target->max_stack_b = max_value;
}

void	find_max_min_a(t_stack_list **a, t_target_node *target)
{
	t_stack_list	*temp;
	int				max_value;
	int				min_value;

	if (*a == NULL)
		return ;
	temp = *a;
	max_value = temp->data;
	min_value = temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data > max_value)
			max_value = temp->data;
		else if (min_value > temp->data)
			min_value = temp->data;
	}
	target->min_stack_a = min_value;
	target->max_stack_a = max_value;
}
