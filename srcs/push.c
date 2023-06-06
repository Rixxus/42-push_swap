/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:54:09 by rmount            #+#    #+#             */
/*   Updated: 2023/06/06 14:58:31 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	push
*	push_to_a
*	push_to_b
*/

/*
#	push
•	This function is used in the push_to_a and push_to_b functions.
•	If the from_stack is empty we return null.
•	We set the temp node to = from_stack, then from_stack to from_stack->next.
•	Finally, we add the temp node to the front of the to_stack. 	
*/
void	push(t_node **from_stack, t_node **to_stack)
{
	t_node	*tmp;

	if (stack_size(*from_stack) == 0)
		return ;
	tmp = *from_stack;
	*from_stack = (*from_stack)->next;
	add_to_front(to_stack, tmp);
}

/*
#	push_to_a
•	This function uses the push function to remove the top node from
•	stack_b and add it to the front of stack_a.
*/
void	push_to_a(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

/*
#	push_to_b
•	This function uses the push function to remove the top node from
•	stack_a and add it to the front of stack_b.
*/
void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}