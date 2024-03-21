/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:21:22 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 14:49:39 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stack_list **a, t_stack_list **b,
t_cheapest_node *cheapest)
{
	while (cheapest->ra-- > 0)
		write_inst_rotate(a, b, "ra");
	while (cheapest->rb-- > 0)
		write_inst_rotate(a, b, "rb");
	while (cheapest->rra-- > 0)
		write_inst_reverse_rotate(a, b, "rra");
	while (cheapest->rrb-- > 0)
		write_inst_reverse_rotate(a, b, "rrb");
	while (cheapest->rr-- > 0)
		write_inst_rotate(a, b, "rr");
	while (cheapest->rrr-- > 0)
		write_inst_reverse_rotate(a, b, "rrr");
	while (cheapest->pb-- > 0)
		write_inst_push(a, b, "pb");
}

void	sort_multi(t_stack_list **a, t_stack_list **b)
{
	t_target_node	*target;
	t_moves_node	*inst_a;
	t_cheapest_node	*cheapest;

	target = malloc(sizeof(t_target_node));
	inst_a = malloc(sizeof(t_moves_node));
	cheapest = malloc(sizeof(t_cheapest_node));
	target->max_stack_b = 0;
	target->min_stack_b = 0;
	write_inst_push(a, b, "pb");
	write_inst_push(a, b, "pb");
	while ((lst_len(a)) != 3)
	{
		find_max_min_b(b, target);
		find_cheapest_move(a, b, target, cheapest);
		move_cheapest(a, b, cheapest);
	}
	sort_three(a, b);
	sort_stack_a(a, b, target, inst_a);
	free(target);
	free(inst_a);
	free(cheapest);
}
