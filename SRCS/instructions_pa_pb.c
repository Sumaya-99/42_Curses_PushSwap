/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pa_pb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:20:28 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 16:42:59 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	if ((*b)->next != NULL)
		*b = (*b)->next;
	else
		*b = NULL;
	temp->next = *a;
	*a = temp;
}

void	ft_pb(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	write_inst_push(t_stack_list **a, t_stack_list **b, char *str)
{
	if ((ft_strcmp(str, "pa")) == 0)
	{
		ft_pa (a, b);
		write(1, "pa\n", 3);
	}
	else if ((ft_strcmp(str, "pb")) == 0)
	{
		ft_pb (a, b);
		write(1, "pb\n", 3);
	}
}
