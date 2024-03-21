/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:21:36 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 09:21:38 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*sorting;

	sorting = *a;
	if (sorting->data > sorting->next->data)
	{
		if (sorting->data > sorting->next->next->data)
			write_inst_rotate(a, b, "ra");
	}
	else if (sorting->next->data > sorting->data)
	{
		if (sorting->next->data > sorting->next->next->data)
			write_inst_reverse_rotate(a, b, "rra");
	}
	if ((*a)->data > (*a)->next->data)
		write_inst_swap(a, b, "sa");
}
