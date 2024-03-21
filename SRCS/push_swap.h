/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:31:32 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/20 14:00:45 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct stack
{
	int						data;
	struct stack			*next;
	struct target_node		*target;
	struct moves_node		*inst;
	struct cheapest_node	*cheapest;
}							t_stack_list;

typedef struct target_node
{
	int			max_stack_b;
	int			min_stack_b;
	int			max_stack_a;
	int			min_stack_a;
}				t_target_node;

typedef struct moves_node
{
	int		total;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		pb;
}			t_moves_node;

typedef struct cheapest_node
{
	int		total;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		pb;
}			t_cheapest_node;

/*PARSING*/
char			**split_arg(char const *s);
t_stack_list	*create_stack(t_stack_list **a, char **str);
void			ft_printList(t_stack_list *head);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			check_arg(int c, char **av);
char			*join_arg(int c, char **av);
char			*ft_strdup(const char *s1);
int				ft_strcmp(char *s1, char *s2);
int				conv_num(t_stack_list **a, char *str, char **splitted);
int				check_for_overflow(int result, int sign, char a);

/*FREE FUNCTIONS AND ERROR*/
void			free_str(char *str);
void			ft_free_str(char **spl);
void			ft_free_list(t_stack_list **list);
void			last_free_list(t_stack_list **list);
void			ft_free_list_str(t_stack_list **list, char **spl);
void			error_write(void);

/*INSTRCUTIONS*/
void			ft_sa(t_stack_list **a);
void			ft_sb(t_stack_list **b);
void			ft_ss(t_stack_list **a, t_stack_list **b);
void			ft_ra(t_stack_list **a);
void			ft_rb(t_stack_list **b);
void			ft_rr(t_stack_list **a, t_stack_list **b);
void			ft_rra(t_stack_list **a);
void			ft_rrb(t_stack_list **b);
void			ft_rrr(t_stack_list **a, t_stack_list **b);
void			ft_pa(t_stack_list **a, t_stack_list **b);
void			ft_pb(t_stack_list **a, t_stack_list **b);
void			write_inst_swap(t_stack_list **a, t_stack_list **b, char *str);
void			write_inst_rotate(t_stack_list **a, t_stack_list **b,
					char *str);
void			write_inst_reverse_rotate(t_stack_list **a, t_stack_list **b,
					char *str);

/*SORTING*/
int				lst_len(t_stack_list **lst);
t_stack_list	*list_last(t_stack_list **a);
int				list_position(t_stack_list **stack, int num);
t_stack_list	*ft_sort(t_stack_list **a, t_stack_list **b);
void			sort_three(t_stack_list **a, t_stack_list **b);
void			sort_four(t_stack_list **a, t_stack_list **b);
t_stack_list	*sort_five(t_stack_list **a, t_stack_list **b);
void			sort_multi(t_stack_list **a, t_stack_list **b);
void			find_max_min_b(t_stack_list **b, t_target_node *target);
void			find_cheapest_move(t_stack_list **a, t_stack_list **b,
					t_target_node *target, t_cheapest_node *cheapest);
void			check_move_max_b(t_stack_list **b, t_moves_node *inst_b,
					t_target_node *target);
void			check_move_min_b(t_stack_list **b, t_moves_node *inst_b,
					t_target_node *target);
void			find_new_num(t_stack_list **b, int target_num,
					t_target_node *target, t_moves_node *inst_b);
void			get_a(t_stack_list **a, t_moves_node *inst_a, int num, int c);
void			check_move_min(t_stack_list **b);
int				ft_is_sorted(t_stack_list **a);
void			sort_stack_a(t_stack_list **a, t_stack_list **b,
					t_target_node *target, t_moves_node *inst_a);
void			move_max(t_stack_list **a, t_stack_list **b,
					t_target_node *target, t_moves_node *inst_a);
void			move_min(t_stack_list **a, t_stack_list **b,
					t_target_node *target, t_moves_node *inst_a);
void			find_max_min_a(t_stack_list **a, t_target_node *target);
void			find_new_num_a(t_stack_list **a, t_stack_list **b,
					int num, t_moves_node *inst_a);
void			check_max_top(t_stack_list **a, t_stack_list **b,
					t_moves_node *inst_b, t_target_node *target);
void			find_new_num_in_a(t_stack_list **a, t_stack_list **b,
					int num, t_moves_node *inst_a);
void			write_inst_push(t_stack_list **a, t_stack_list **b,
					char *str);
#endif