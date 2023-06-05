/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:23:27 by rmount            #+#    #+#             */
/*   Updated: 2023/06/05 16:56:43 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	sort_three
*	sort_four
*	sort_five
*   simple_sort
*	radix_sort
*/

void	sort_three(t_node **stack_a)
{
	if ((*stack_a)->index == get_min(stack_a, -1)
		&& (*stack_a)->next->index != get_min(stack_a, get_min(stack_a, -1)))
	{
		rotate_up_a(stack_a);
		swap_a(stack_a);
		rotate_down_a(stack_a);
	}
	else if ((*stack_a)->index == get_min(stack_a, get_min(stack_a, -1)))
	{
		if ((*stack_a)->next->index == get_min(stack_a, -1))
			swap_a(stack_a);
		else
			rotate_down_a(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == get_min(stack_a, -1))
			rotate_up_a(stack_a);
		else
		{
			swap_a(stack_a);
			rotate_down_a(stack_a);
		}
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_to_node(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_up_a(stack_a);
	else if (distance == 2)
	{
		rotate_up_a(stack_a);
		rotate_up_a(stack_a);
	}
	else if (distance == 3)
		rotate_down_a(stack_a);
	if (is_sorted(stack_a))
		return ;
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_to_a(stack_b, stack_a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_to_node(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_up_a(stack_a);
	else if (distance == 2)
	{
		rotate_up_a(stack_a);
		rotate_up_a(stack_a);
	}
	else if (distance == 3)
	{
		rotate_down_a(stack_a);
		rotate_down_a(stack_a);
	}
	else if (distance == 4)
		rotate_down_a(stack_a);
	if (is_sorted(stack_a))
		return ;
	push_to_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push_to_a(stack_b, stack_a);
}

void	simple_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || stack_size(*stack_a) == 0
		|| stack_size(*stack_a) == 1)
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = stack_size(*stack_a);
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_up_a(stack_a);
			else
				push_to_b(stack_a, stack_b);
		}
		while (stack_size(*stack_b) != 0)
			push_to_a(stack_b, stack_a);
		i++;
	}
}