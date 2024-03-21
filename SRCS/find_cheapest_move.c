/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:20:10 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 09:20:12 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cheap(t_moves_node *inst_a, t_moves_node *inst_b,
		t_cheapest_node *cheapest, int c)
{
	inst_a->total = inst_a->ra + inst_a->rra + inst_a->rrr
		+ inst_b->rb + inst_a->rr + inst_b->rrb + inst_a->pb;
	if (c == 1 || inst_a->total < cheapest->total)
	{
		cheapest->total = inst_a->total;
		cheapest->ra = inst_a->ra;
		cheapest->rra = inst_a->rra;
		cheapest->rrr = inst_a->rrr;
		cheapest->rr = inst_a->rr;
		cheapest->rb = inst_b->rb;
		cheapest->rrb = inst_b->rrb;
		cheapest->pb = inst_a->pb;
	}
}

void	check_doubles(t_moves_node *inst_a, t_moves_node *inst_b)
{
	inst_a->rrr = 0;
	inst_a->rr = 0;
	while (inst_a->ra != 0 && inst_b->rb != 0)
	{
		inst_a->ra--;
		inst_b->rb--;
		inst_a->rr++;
	}
	while (inst_a->rra != 0 && inst_b->rrb != 0)
	{
		inst_a->rra--;
		inst_b->rrb--;
		inst_a->rrr++;
	}
}

void	find_cheapest_move(t_stack_list **a, t_stack_list **b,
t_target_node *target, t_cheapest_node *cheapest)
{
	t_stack_list	*temp;
	t_moves_node	*inst_b;
	t_moves_node	*inst_a;
	int				size;
	int				c;

	temp = *a;
	c = 0;
	inst_b = malloc(sizeof(t_moves_node));
	inst_a = malloc(sizeof(t_moves_node));
	size = lst_len(a);
	while (c++ < size)
	{
		get_a(a, inst_a, temp->data, c - 1);
		if (temp->data > target->max_stack_b
			|| temp->data < target->min_stack_b)
			check_move_max_b(b, inst_b, target);
		else
			find_new_num(b, temp->data, target, inst_b);
		check_doubles(inst_a, inst_b);
		calculate_cheap(inst_a, inst_b, cheapest, c);
		temp = temp->next;
	}
	free(inst_b);
	free(inst_a);
}
