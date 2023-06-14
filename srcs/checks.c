/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:58:56 by rmount            #+#    #+#             */
/*   Updated: 2023/06/14 18:45:42 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	is_repeat
*	is_num
*	check_args
*	which_sort
*/

/*
#	is_repeat
•	This function checks whether the current number is duplicated in what 
•	remains of argv. num is the current number we're looking for and i
•	is the index of the current number.
•	If we find num in the array at any point, we return 1.
*/
int	is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

/*
#	is_num
•	This function checks whether a string is a number, accounting for
•	a possible '-' symbol at the start.
*/
int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	if (!ft_isdigit(num[i]))
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
#	check_args
•	This function checks the arguments and splits them if they are given as
•	a single string delimited by spaces.
•	We then check whether each arg is a number, whether it is repeated,
•	and whether it fits into an int. If any of those checks fail an
•	error message is printed and the program exits.
•	Finally, if we have used split on argv, we free argv to prevent
•	memory leaks.
*/
void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;	

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			exit(0);
	}
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!is_num(argv[i]) || is_repeat(tmp, argv, i) || !*argv[i])
			error_message();
		tmp = ft_atol(argv[i]);
		if (ft_strlen(argv[i]) > 11 || tmp < -2147483648 || tmp > 2147483647)
			error_message();
		i++;
	}
	if (argc == 2)
		ft_free(argv);
}

/*
#	which_sort
•	This function checks which type of sort to do based on stack_a's size. 
•	5 or less numbers can be sorted using the simple sort,
•	but for anything larger we use a radix sort.
*/
void	which_sort(t_node **stack_a, t_node **stack_b)
{
	if (stack_size(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
