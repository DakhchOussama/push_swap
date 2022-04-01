/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:06:52 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/27 20:11:15 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	check_free(t_stack	*stack, char	*msg)
{
	if (stack)
		if (stack->stack_a.array)
			free(stack->stack_a.array);
	if (stack->stack_b.array)
		free(stack->stack_b.array);
	if (msg != NULL)
		write(1, "ERROR\n", 6);
	exit(EXIT_SUCCESS);
}

void	check_error(char	*msg)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(msg))
	{
		write(1, &msg[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

int	ft_check_duplicates(t_stack	*stacks, int number)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.sizeadd)
	{
		if (stacks->stack_a.array[i] == number)
			return (0);
		i++;
	}
	return (1);
}
