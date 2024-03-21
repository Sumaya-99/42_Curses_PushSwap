/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:48:07 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/15 15:48:27 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_move(t_stack_list **a, t_stack_list **b, t_moves_node *inst_a)
{
	while (inst_a->ra-- > 0)
		write_inst_rotate(a, b, "ra");
	while (inst_a->rra-- > 0)
		write_inst_reverse_rotate(a, b, "rra");
}

void	last_sort(t_stack_list **a, t_stack_list **b,
		t_target_node *target, t_moves_node *inst_a)
{
	int	size;
	int	position;

	inst_a->ra = 0;
	inst_a->rra = 0;
	if ((*a)->data != target->min_stack_a)
	{
		position = list_position(a, target->min_stack_a);
		size = lst_len(a);
		if (position + 1 > size / 2)
			inst_a->rra = (size - position);
		else
			inst_a->ra = position;
		while (inst_a->ra-- > 0)
			write_inst_rotate(a, b, "ra");
		while (inst_a->rra-- > 0)
			write_inst_reverse_rotate(a, b, "rra");
	}
}

void	sort_stack_a(t_stack_list **a, t_stack_list **b,
t_target_node *target, t_moves_node *inst_a)
{
	target->max_stack_a = 0;
	target->min_stack_a = 0;
	while ((*b) != NULL)
	{
		find_max_min_a(a, target);
		if ((*b)->data > target->max_stack_a)
			move_max(a, b, target, inst_a);
		else if ((*b)->data < target->min_stack_a)
			move_min(a, b, target, inst_a);
		else
			find_new_num_a(a, b, (*b)->data, inst_a);
	}
	find_max_min_a(a, target);
	last_sort(a, b, target, inst_a);
	ft_sort(a, b);
}
