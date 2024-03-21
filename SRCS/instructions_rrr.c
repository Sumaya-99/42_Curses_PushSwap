/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:20:44 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 16:42:52 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack_list **a)
{
	t_stack_list	*temp;
	t_stack_list	*new_stack;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	new_stack = NULL;
	while (temp->next != NULL)
	{
		new_stack = temp;
		temp = temp->next;
	}
	temp->next = *a;
	*a = temp;
	new_stack->next = NULL;
}

void	ft_rrb(t_stack_list **b)
{
	t_stack_list	*temp;
	t_stack_list	*new_stack;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	new_stack = NULL;
	while (temp->next != NULL)
	{
		new_stack = temp;
		temp = temp->next;
	}
	temp->next = *b;
	*b = temp;
	new_stack->next = NULL;
}

void	ft_rrr(t_stack_list **a, t_stack_list **b)
{
	ft_rra (a);
	ft_rrb (b);
}

void	write_inst_reverse_rotate(t_stack_list **a, t_stack_list **b, char *str)
{
	if ((ft_strcmp(str, "rra")) == 0)
	{
		ft_rra (a);
		write(1, "rra\n", 4);
	}
	else if ((ft_strcmp(str, "rrb")) == 0)
	{
		ft_rrb (b);
		write(1, "rrb\n", 4);
	}
	else if ((ft_strcmp(str, "rrr")) == 0)
	{
		ft_rrr (a, b);
		write(1, "rrr\n", 4);
	}
}
