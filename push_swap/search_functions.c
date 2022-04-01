/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:28:47 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 15:33:05 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_number(int	*array, int size, int div, int chunks)
{
	int	num;

	num = array[(size * div) / chunks];
	return (num);
}

int	search_small(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->stack_a.sizeadd)
	{
		if (stack->stack_a.array[i] <= num)
			return (i);
		i++;
	}
	return (-1);
}

int	search_bigg(t_num *stack_b)
{
	int	i;
	int	index;

	i = 0;
	index = i;
	while (i < stack_b->sizeadd)
	{
		if (stack_b->array[index] < stack_b->array[i])
			index = i;
		i++;
	}
	return (index);
}

void	find_bigg_num(t_stack *stack)
{
	int	index;
	int	length;

	index = search_bigg(&stack->stack_b);
	length = stack->stack_b.sizeadd / 2;
	while (index != 0)
	{
		if (index <= length)
			ra_rb(&stack->stack_b, OK, 'b');
		else
			rra_rrb(&stack->stack_b, OK, 'b');
		index = search_bigg(&stack->stack_b);
	}
}

void	find_small(t_stack *stack)
{
	int	num;

	num = small_num(&stack->stack_a);
	while (num != 0)
	{
		if (num <= 2)
			ra_rb(&stack->stack_a, OK, 'a');
		else
			rra_rrb(&stack->stack_a, OK, 'a');
		num = small_num(&stack->stack_a);
	}
}
