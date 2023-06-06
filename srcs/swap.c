/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:54:23 by rmount            #+#    #+#             */
/*   Updated: 2023/06/06 16:14:58 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	swap
*	swap_a
*	swap_b
*	swap_both
*/

/*
#	...
•	This function is used in the push_to_a and push_to_b functions.
•	If the from_stack is empty we return null.
•	We set the temp node to = from_stack, then from_stack to from_stack->next.
•	Finally, we add the temp node to the front of the to_stack. 	
*/
void	swap(t_node **stack)
{
	t_node	*tmp;

	if (stack_size(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap_a(t_node **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_node **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}