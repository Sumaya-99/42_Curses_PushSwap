/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ss.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:20:55 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 13:49:32 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack_list **a)
{
	t_stack_list	*temp;
	int				swap;

	if (!*a)
		return ;
	temp = *a;
	if (temp != NULL && temp->next != NULL)
	{
		swap = temp->data;
		temp->data = temp->next->data;
		temp->next->data = swap;
	}
}

void	ft_sb(t_stack_list **b)
{
	t_stack_list	*temp;
	int				swap;

	if (!b)
		return ;
	temp = *b;
	if (temp != NULL && temp->next != NULL)
	{
		swap = temp->data;
		temp->data = temp->next->data;
		temp->next->data = swap;
	}
}

void	ft_ss(t_stack_list **a, t_stack_list **b)
{
	ft_sa (a);
	ft_sb (b);
}

void	write_inst_swap(t_stack_list **a, t_stack_list **b, char *str)
{
	if ((ft_strcmp(str, "sa")) == 0)
	{
		ft_sa (a);
		write(1, "sa\n", 3);
	}
	else if ((ft_strcmp(str, "sb")) == 0)
	{
		ft_sb (b);
		write(1, "sb\n", 3);
	}
	else if ((ft_strcmp(str, "ss")) == 0)
	{
		ft_ss (a, b);
		write(1, "ss\n", 3);
	}
}
