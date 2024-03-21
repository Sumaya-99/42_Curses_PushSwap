/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:28:04 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 16:43:08 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int c, char **av)
{
	int	count;
	int	a;

	count = 1;
	while (count < c)
	{
		a = 0;
		if (!av[count][0])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (av[count][0] == ' ')
		{
			while (av[count][a] == ' ')
				a++;
			if (av[count][a] == '\0')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		count++;
	}
}
