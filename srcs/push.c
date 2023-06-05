/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:54:09 by rmount            #+#    #+#             */
/*   Updated: 2023/06/05 17:04:05 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	push
*	push_to_a
*	push_to_b
*/

void	push(t_node **stack_from, t_node **stack_dst)
{
	t_node	*tmp;

	if (stack_size(*stack_from) == 0)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	add_to_front(stack_dst, tmp);
}

void	push_to_a(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}