/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_new_num_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:20:23 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 14:51:41 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num_a(t_stack_list **a, int num)
{
	t_stack_list	*temp;
	int				smallest_largest;

	temp = *a;
	smallest_largest = INT_MAX;
	while (temp != NULL)
	{
		if (smallest_largest > temp->data && temp->data > num)
			smallest_largest = temp->data;
		temp = temp->next;
	}
	return (smallest_largest);
}

void	find_new_num_a(t_stack_list **a, t_stack_list **b,
		int num, t_moves_node *inst_a)
{
	int	position;
	int	size;
	int	nbr;

	inst_a->ra = 0;
	inst_a->rra = 0;
	size = lst_len (a);
	nbr = get_num_a (a, num);
	position = list_position (a, nbr);
	if ((*a)->data != nbr)
	{
		if (position + 1 > size / 2)
			inst_a->rra = (size - position);
		else
			inst_a->ra = position;
		while (inst_a->ra-- > 0)
			write_inst_rotate(a, b, "ra");
		while (inst_a->rra-- > 0)
			write_inst_reverse_rotate(a, b, "rra");
	}
	write_inst_push(a, b, "pa");
}

int	lst_len(t_stack_list **lst)
{
	int				a;
	t_stack_list	*temp;

	a = 0;
	temp = *lst;
	while (temp)
	{
		temp = temp->next;
		a++;
	}
	return (a);
}

t_stack_list	*list_last(t_stack_list **a)
{
	t_stack_list	*temp;

	temp = *a;
	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
