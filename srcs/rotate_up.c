/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:15:11 by rmount            #+#    #+#             */
/*   Updated: 2023/06/05 17:01:11 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	rotate_up
*	rotate_up_a
*	rotate_up_b
*	rotate_up_both
*/

/* The base rotate function, called by specific rotate functions */
void	rotate_up(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	if (stack_size(*stack) < 2)
		return ;
	tail = get_last_node(*stack);
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;
}

/* Rotates the */
void	rotate_up_a(t_node **stack_a)
{
	rotate_up(stack_a);
	ft_putendl_fd("ra", 1);
}

/* Rotates the */
void	rotate_up_b(t_node **stack_b)
{
	rotate_up(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rotate_up_both(t_node **stack_a, t_node **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return ;
	rotate_up(stack_a);
	rotate_up(stack_b);
	ft_putendl_fd("rr", 1);
}