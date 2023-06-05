/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:14:13 by rmount            #+#    #+#             */
/*   Updated: 2023/06/05 17:01:45 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	rotate_down
*	rotate_down_a
*	rotate_down_b
*	rotate_down_both
*/

void	rotate_down(t_node **stack)
{
	t_node	*prev_tail;
	t_node	*tail;

	if (stack_size(*stack) < 2)
		return ;
	prev_tail = *stack;
	while (prev_tail->next->next)
		prev_tail = prev_tail->next;
	tail = prev_tail->next;
	prev_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rotate_down_a(t_node **stack_a)
{
	rotate_down(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rotate_down_b(t_node **stack_b)
{
	rotate_down(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rotate_down_both(t_node **stack_a, t_node **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return ;
	rotate_down(stack_a);
	rotate_down(stack_b);
	ft_putendl_fd("rrr", 1);
}
