/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:19:50 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 09:19:50 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <fcntl.h>

void	write_result(t_stack_list **a)
{
	if ((ft_is_sorted(a)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	last_free_list(a);
}

void	get_line(t_stack_list **a, t_stack_list **b)
{
	char	*get_line;

	get_line = NULL;
	get_line = get_next_line(0);
	while (get_line)
	{
		write_inst(&get_line, a, b);
		free_str(get_line);
		get_line = get_next_line(0);
	}
	write_result(a);
}

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
			get_line(&a, &b);
		last_free_list(&a);
		last_free_list(&b);
	}
	else
		return (0);
}
