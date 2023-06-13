/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:15:11 by rmount            #+#    #+#             */
/*   Updated: 2023/06/13 13:35:38 by rmount           ###   ########.fr       */
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

/*
#	rotate_up
•	This function takes a stack and moves all nodes up one space. The top 
•	node is moved to the bottom.
•	If the stack only has one node, we can't rotate it and return null.
•	We can use the get_last_node function to get the tail directly (as we
•	don't need the second to last node for this rotate), and set old_tail to it.
•	We set old_head to stack, set stack to the next node, set old tail's next to
•	old_head, making it the tail, and then old head's next to null, severing it
•	from the top of the list.
*/
void	rotate_up(t_node **stack)
{
	t_node	*old_tail;
	t_node	*old_head;

	if (stack_size(*stack) < 2)
		return ;
	old_tail = get_last_node(*stack);
	old_head = *stack;
	*stack = (*stack)->next;
	old_tail->next = old_head;
	old_head->next = NULL;
}

/* 
#	rotate_up_a
•	This function uses the rotate_up function on stack_a, 
•	removing the head and adding it to the bottom of the stack,
•	then prints the move to the standard output.
*/
void	rotate_up_a(t_node **stack_a)
{
	rotate_up(stack_a);
	ft_printf("ra\n");
}

/* 
#	rotate_up_b
•	This function uses the rotate_up function on stack_b, 
•	removing the head and adding it to the bottom of the stack,
•	then prints the move to the standard output.
*/
void	rotate_up_b(t_node **stack_b)
{
	rotate_up(stack_b);
	ft_printf("rb\n");
}

/* 
#	rotate_up_both
•	This function uses the rotate_up function on on stack_a and stack_b, 
•	removing the head and adding it to the bottom of each stack,
•	then prints the move to the standard output.
*/
void	rotate_up_both(t_node **stack_a, t_node **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return ;
	rotate_up(stack_a);
	rotate_up(stack_b);
	ft_printf("rr\n");
}