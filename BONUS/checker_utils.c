/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:19:42 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/19 09:19:42 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	write_inst(char **get_line, t_stack_list **a, t_stack_list **b)
{
	if ((ft_strcmp(*get_line, "pa\n")) == 0)
		return (ft_pa(a, b));
	if ((ft_strcmp(*get_line, "pb\n")) == 0)
		return (ft_pb(a, b));
	if ((ft_strcmp(*get_line, "sa\n")) == 0)
		return (ft_sa(a));
	if ((ft_strcmp(*get_line, "sb\n")) == 0)
		return (ft_sb(b));
	if ((ft_strcmp(*get_line, "ss\n")) == 0)
		return (ft_ss(a, b));
	if ((ft_strcmp(*get_line, "ra\n")) == 0)
		return (ft_ra(a));
	if ((ft_strcmp(*get_line, "rb\n")) == 0)
		return (ft_rb(b));
	if ((ft_strcmp(*get_line, "rr\n")) == 0)
		return (ft_rr(a, b));
	if ((ft_strcmp(*get_line, "rra\n") == 0))
		return (ft_rra(a));
	if ((ft_strcmp(*get_line, "rrb\n") == 0))
		return (ft_rrb(b));
	if ((ft_strcmp(*get_line, "rrr\n") == 0))
		return (ft_rrr(a, b));
	free_str(*get_line);
	last_free_list(b);
	ft_free_list(a);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while ((s1[n] != '\0' || s2[n] != '\0') && s1[n] == s2[n])
		n++;
	return (s1[n] - s2[n]);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	b;

	if (!dstsize)
		return (ft_strlen(src));
	b = 0;
	while (b < (dstsize - 1) && src[b] != '\0')
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		str = (char *)malloc(1);
		if (!str)
			free_str(str);
		str[0] = '\0';
		return (str);
	}
	if (len > (slen - start))
		len = (slen - start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
