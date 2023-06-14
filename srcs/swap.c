/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:54:23 by rmount            #+#    #+#             */
/*   Updated: 2023/06/14 11:28:42 by rmount           ###   ########.fr       */
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
#	swap
•	This function is used in the push_to_a and push_to_b functions.
•	If the from_stack is empty we return null.
•	We set the temp node to = from_stack, then from_stack to from_stack->next.
•	Finally, we add the temp node to the front of the to_stack, effectively
•	swapping the first two nodes in the stack. 	
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

/*
#	swap_a
•	This function uses the swap function on stack_a, swapping the position
•	of the first 2 nodes, then prints the move to the standard output.
*/
void	swap_a(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

/*
#	swap_b
•	This function uses the swap function on stack_b, swapping the position
•	of the first 2 nodes, then prints the move to the standard output.
*/
void	swap_b(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

/*
#	swap_both
•	This function uses the swap function on both stack_a and stack_b, 
•	swapping the position of the first 2 nodes in each, then prints
•	the move to the standard output.
*/
void	swap_both(t_node **stack_a, t_node **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
