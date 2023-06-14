/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:20:59 by rmount            #+#    #+#             */
/*   Updated: 2023/06/14 14:53:42 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	new_node
*	get_last_node
*	add_to_front
*	add_to_back
*/

/*
#	new_node
•	This functions make a new node for the linked list using the struct defined
•	in the header file. 
•	We create a new NULL t_node, malloc it the correct size. If the malloc fails
•	we return NULL.
•	The node is assigned the number passed on calling new_node, gives every index
•	a value of -1 and sets the next to NULL, then returns the pointer to the node.
*/
t_node	*new_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> number = number;
	new_node -> index = -1;
	new_node -> next = NULL;
	return (new_node);
}

/*
#	get_last_node
•	This function traverses the stack until it reaches the 
•	last node, which it returns.
*/
t_node	*get_last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

/*
#	add_to_front
•	This function takes the stack and a new node, sets the 
•	new node's next to stack, then reassigning stack to
•	the new node, making it the first item on the stack.
*/
void	add_to_front(t_node **stack, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node -> next = *stack;
	*stack = new_node;
}

/*
#	add_to_back
•	This function takes the stack and a new node, finds the last node 
•	of the stack and sets its next to the new_node.
*/
void	add_to_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!new_node)
		return ;
	if (*stack)
	{
		temp = get_last_node(*stack);
		temp -> next = new_node;
	}
	else
		*stack = new_node;
}
