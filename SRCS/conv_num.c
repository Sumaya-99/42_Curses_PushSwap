/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:04:19 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/15 14:13:16 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_overflow(int result, int sign, char a)
{
	if ((a == '+' && result == '+') || (a == '-' && result == '-'))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	if (sign == 1)
	{
		if ((result == INT_MAX / 10 && a > '7') || result > INT_MAX / 10)
			return (1);
	}
	else if (sign == -1)
	{
		if ((result == INT_MAX / 10 && a > '8') || result > INT_MAX / 10)
			return (1);
	}
	return (0);
}

int	conv_num(t_stack_list **a, char *str, char **splitted)
{
	int	sign;
	int	result;
	int	c;

	sign = 1;
	result = 0;
	c = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-')
		sign *= -1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		if ((check_for_overflow(result, sign, str[c])))
		{
			if ((a != NULL && *a != NULL) || a == NULL || splitted != NULL)
			{
				ft_free_str(splitted);
				ft_free_list(a);
			}
		}
		result = result * 10 + str[c] - '0';
		c++;
	}
	return (result * sign);
}
