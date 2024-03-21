/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:21:15 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 09:21:17 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_list	*a;
	t_stack_list	*b;
	char			*str;
	char			**split;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		check_arg (ac, av);
		str = join_arg (ac, av);
		split = split_arg (str);
		free_str (str);
		create_stack (&a, split);
		if (a == NULL)
			ft_free_list_str(&a, split);
		else
		{
			ft_sort (&a, &b);
			last_free_list (&a);
		}
	}
	else
		return (0);
}
