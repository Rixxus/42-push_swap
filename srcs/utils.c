/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:00:09 by rmount            #+#    #+#             */
/*   Updated: 2023/06/13 14:47:04 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Functions in file:
*	error_message
*	ft_free
*/

/*
#	error_message
•	This function is called when a check fails and prints "Error" to the
•	standard output then exits the program.
*/
void	error_message()
{
	ft_printf("Error\n");
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

