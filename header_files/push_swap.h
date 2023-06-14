/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:00:12 by rmount            #+#    #+#             */
/*   Updated: 2023/06/14 19:27:07 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}	t_node;

/* checks.c */
int				is_repeat(int num, char **argv, int i);
int				is_num(char *num);
void			check_args(int argc, char **argv);
void			which_sort(t_node **stack_a, t_node **stack_b);

/* list.c */
t_node			*new_node(int number);
t_node			*get_last_node(t_node *head);
void			add_to_front(t_node **stack, t_node *new_node);
void			add_to_back(t_node **stack, t_node *new_node);

/* push.c */
void			push(t_node **from_stack, t_node **to_stack);
void			push_to_a(t_node **stack_b, t_node **stack_a);
void			push_to_b(t_node **stack_a, t_node **stack_b);

/* rotate_down.c */
void			rotate_down(t_node **stack);
void			rotate_down_a(t_node **stack_a);
void			rotate_down_b(t_node **stack_b);
void			rotate_down_both(t_node **stack_a, t_node **stack_b);

/* rotate_up.c */
void			rotate_up(t_node **stack);
void			rotate_up_a(t_node **stack_a);
void			rotate_up_b(t_node **stack_b);
void			rotate_up_both(t_node **stack_a, t_node **stack_b);

/* sort.c */
void			sort_three(t_node **stack_a);
void			sort_four(t_node **stack_a, t_node **stack_b);
void			sort_five(t_node **stack_a, t_node **stack_b);
void			simple_sort(t_node **stack_a, t_node **stack_b);
void			radix_sort(t_node **stack_a, t_node **stack_b);

/* stack.c */
int				get_min_i(t_node **stack, int number);
t_node			*get_smallest_value_node(t_node **stack);
void			index_stack(t_node **stack);
void			new_stack(t_node **stack, int argc, char **argv);
int				get_spaces_to_node(t_node **stack, int index);

/* swap.c */
void			swap(t_node **stack);
void			swap_a(t_node **stack_a);
void			swap_b(t_node **stack_b);
void			swap_both(t_node **stack_a, t_node **stack_b);

/* utils.c */
void			error_message(void);
void			ft_free(char **str);
int				is_sorted(t_node **stack);
int				stack_size(t_node *head);
void			free_stack(t_node **stack);

#endif