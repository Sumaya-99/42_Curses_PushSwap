/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:21:31 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/21 13:57:00 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*temp;
	int				num1;

	num1 = (*a)->data;
	write_inst_push(a, b, "pb");
	sort_three (a, b);
	if (num1 > (*a)->next->data && num1 < (*a)->next->next->data)
	{
		write_inst_reverse_rotate (a, b, "rra");
		write_inst_push (a, b, "pa");
		write_inst_rotate (a, b, "ra");
		write_inst_rotate (a, b, "ra");
	}
	else
		write_inst_push(a, b, "pa");
	temp = *a;
	if (temp->data > temp->next->data)
	{
		temp = temp->next;
		if ((*a)->data > temp->next->data
			&& (*a)->data > temp->next->next->data)
			write_inst_rotate(a, b, "ra");
		else if ((*a)->data < temp->next->data)
			write_inst_swap(a, b, "sa");
	}
}
