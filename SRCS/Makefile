# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:37:34 by suhelal           #+#    #+#              #
#    Updated: 2024/03/20 09:54:09 by suhelal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES 	   = push_swap.c error_free.c sorting_three.c sorting.c conversion.c instructions_rrr.c instructions_ss.c instructions_rr.c check_argument.c \
join_arg.c push_swap_utils.c find_max_min.c find_new_num_a.c move_stack_a.c sort_stack_a.c split_arg.c move_b_num.c find_cheapest_move.c \
sort_multi.c sorting_four.c instructions_pa_pb.c conv_num.c \

BFILES = checker.c checker_utils.c error_free.c sorting_three.c sorting.c conversion.c instructions_rrr.c instructions_ss.c instructions_rr.c check_argument.c \
join_arg.c find_max_min.c find_new_num_a.c move_stack_a.c sort_stack_a.c split_arg.c move_b_num.c find_cheapest_move.c \
sort_multi.c sorting_four.c instructions_pa_pb.c conv_num.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -g3 

NAME	= push_swap

BONUS = checker_swap

all: $(NAME) $(BONUS)

$(NAME):
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)
	
$(BONUS):
	$(CC) $(CFLAGS) $(BFILES) -o $(BONUS)

clean:
	rm -f $(NAME) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: clean $(NAME) $(BONUS)

