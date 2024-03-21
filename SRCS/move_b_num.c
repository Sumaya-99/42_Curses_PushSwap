/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:21:04 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 09:21:06 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_move_max_b(t_stack_list **b, t_moves_node *inst_b,
		t_target_node *target)
{
	int	position;
	int	size;

	inst_b->rrb = 0;
	inst_b->rb = 0;
	position = list_position(b, target->max_stack_b);
	size = lst_len(b);
	if (position == 0)
		return ;
	else
	{
		if (position > size / 2)
			inst_b->rrb = size - position;
		else
			inst_b->rb = position;
	}
}

int	get_number(t_stack_list **b, int num, t_target_node *target)
{
	t_stack_list	*temp;
	int				smallest_largest;
	int				max_b;

	temp = *b;
	max_b = target->max_stack_b;
	smallest_largest = INT_MIN;
	while (temp != NULL)
	{
		if (smallest_largest < temp->data && temp->data < num
			&& temp->data != max_b)
			smallest_largest = temp->data;
		temp = temp->next;
	}
	return (smallest_largest);
}

void	find_new_num(t_stack_list **b, int target_num,
		t_target_node *target, t_moves_node *inst_b)
{
	int	position;
	int	size;
	int	nbr;

	inst_b->rrb = 0;
	inst_b->rb = 0;
	size = lst_len(b);
	nbr = get_number(b, target_num, target);
	position = list_position(b, nbr);
	if (position == 0)
		return ;
	if (position + 1 > size / 2)
		inst_b->rrb = size - position;
	else
		inst_b->rb = position;
}

void	get_a(t_stack_list **a, t_moves_node *inst_a, int num, int c)
{
	int	size;

	inst_a->pb = 1;
	inst_a->rra = 0;
	inst_a->ra = 0;
	if ((*a)->data == num)
		return ;
	size = lst_len(a);
	if (c + 1 > size / 2)
		inst_a->rra = size - c;
	else
		inst_a->ra = c;
}

int	list_position(t_stack_list **stack, int num)
{
	t_stack_list	*temp;
	int				size;
	int				i;

	i = 0;
	temp = *stack;
	size = lst_len(stack);
	while (i < size)
	{
		if (temp->data == num)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}
