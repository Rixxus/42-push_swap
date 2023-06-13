/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:14:13 by rmount            #+#    #+#             */
/*   Updated: 2023/06/13 13:33:44 by rmount           ###   ########.fr       */
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

/*
#	rotate_down
•	This function takes a stack and moves all nodes down one space. The bottom 
•	node is moved to the top.
•	If the stack only has one node, we can't rotate it and return null.
•	We set new_tail = stack, then while there are two nodes behind new
•	tail we iterate down the stack, setting new tail to be the second
•	last node in the stack.
•	We then set the new_tail's next to null, the new head's next to
•	stack, and stack to the new_head.
*/
void	rotate_down(t_node **stack)
{
	t_node	*new_tail;
	t_node	*new_head;

	if (stack_size(*stack) < 2)
		return ;
	new_tail = *stack;
	while (new_tail->next->next)
		new_tail = new_tail->next;
	new_head = new_tail->next;
	new_tail->next = NULL;
	new_head->next = *stack;
	*stack = new_head;
}

/*
#	rotate_down_a (rra)
•	This function uses the rotate_down function on stack_a, 
•	removing the tail and adding it to the top of the stack,
•	then prints the move to the standard output.
*/
void	rotate_down_a(t_node **stack_a)
{
	rotate_down(stack_a);
	ft_printf("rra\n");
}

/*
#	rotate_down_b (rrb)
•	This function uses the rotate_down function on stack_b, 
•	removing the tail and adding it to the top of the stack,
•	then prints the move to the standard output.
*/
void	rotate_down_b(t_node **stack_b)
{
	rotate_down(stack_b);
	ft_printf("rrb\n");
}

/*
#	rotate_down_both (rrr)
•	This function uses the rotate_down function on stack_a and stack_b, 
•	removing the tail and adding it to the top of each stack,
•	then prints the move to the standard output.
*/
void	rotate_down_both(t_node **stack_a, t_node **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return ;
	rotate_down(stack_a);
	rotate_down(stack_b);
	ft_printf("rrr\n");
}
