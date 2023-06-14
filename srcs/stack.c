/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:41:32 by rmount            #+#    #+#             */
/*   Updated: 2023/06/14 20:01:05 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*   get_min_i
*   get_smallest_value_node
*	index_stack
*	new_stack
*   get_spaces_to_node
*/

/*
#	get_min_i
•	This function traverses the stack, finding the node with the
•	smallest index and returns the index.
*/
int	get_min_i(t_node **stack, int number)
{
	t_node	*head;
	int		smallest_index;

	head = *stack;
	smallest_index = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < smallest_index) && head->index != number)
			smallest_index = head->index;
	}
	return (smallest_index);
}

/*
#	get_smallest_value_node
•	This function traverses the stack, finding the node with the smallest
•	value (number) and returning it.
•	We continue to iterate through, always returning the next largest from
•	the last node because once a node has been given an index it will no
•	longer be looked at in the if condition. 
*/
t_node	*get_smallest_value_node(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->number < min->number))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

/*
#	index_stack
•	This function takes a newly made stack and assigns indexes to each of
•	the nodes, starting at the node with the lowest value and ending with
•	the node with the highest value. 
*/
void	index_stack(t_node **stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_smallest_value_node(stack);
	while (head)
	{
		head->index = index++;
		head = get_smallest_value_node(stack);
	}
}

/*
#	new_stack
•	This function creates the initial stack_a by taking the argv and 
•	creating a new node for each argument, then adding that node to
•	the back of the stack.
•	It then indexes the stack and frees the memory used to split the
•	args (if this was done).
*/
void	new_stack(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		new = new_node(ft_atoi(argv[i]));
		add_to_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(argv);
}

/*
#	get_spaces_to_node
•	This function traverses the stack looking for the supplied index.
•	We increment spaces every time we don't find the matching index,
•	which tells how how many moves getting to it will cost.
*/
int	get_spaces_to_node(t_node **stack, int index)
{
	t_node	*head;
	int		spaces;

	spaces = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		spaces++;
		head = head->next;
	}
	return (spaces);
}
