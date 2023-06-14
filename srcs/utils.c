/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:00:09 by rmount            #+#    #+#             */
/*   Updated: 2023/06/14 19:17:35 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	error_message
*	ft_free
*	is_sorted
*	stack_size
*	free_stack
*/

/*
#	error_message
•	This function is called when a check fails and prints "Error" to the
•	standard output then exits the program.
*/
void	error_message(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

/*
#	ft_free
•	This function is called after using ft_split to free the memory that
•	was used to store the arguments passed to the program.
•	It frees each element (each is an array) and then frees the outer 
•	array too.
*/
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
#	is_sorted
•	This function traverses the stack, comparing the value of each
•	node with the next. 
•	If a number is greater than the next number, the stack is not
•	sorted and we return 0.
•	If every number is larger than the one preceeding it, the stack
•	is sorted and we return 1.
*/
int	is_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head->next)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

/*
#	stack_size
•	This function traverses the stack, incrementing the
•	counter for every node, then returns the count.
*/
int	stack_size(t_node *head)
{
	int	stack_size;

	stack_size = 0;
	while (head)
	{
		stack_size++;
		head = head->next;
	}
	return (stack_size);
}

/*
#	free_stack
•	This function is called after sorting is complete and frees each node
•	of the stack at a time, then frees the pointer to the stack.
•	We must free the stacks after finishing to avoid memory leaks.
*/
void	free_stack(t_node **stack)
{
	t_node	*head;
	t_node	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head ->next;
		free(temp);
	}
	free(stack);
}
