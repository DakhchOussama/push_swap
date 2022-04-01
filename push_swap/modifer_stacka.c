/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifer_stacka.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:04:14 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/27 23:09:59 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redu_stack_a(t_num *stack_a, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->sizeadd--;
}

void	magn_stack_a(t_num *stack_b, t_num *stack_a, int length)
{
	int	i;

	i = length;
	while (i >= 0)
	{
		if (i == 0)
		{
			stack_a->array[0] = stack_b->array[0];
			return ;
		}
		stack_a->array[i] = stack_a->array[i + 1];
		i--;
	}
	stack_a->sizeadd++;
	stack_b->sizeadd--;
}

void	move_top(t_stack *stack, int num)
{
	int	index;

	index = stack->stack_a.sizeadd / 2;
	while (num != 0)
	{
		if (num <= index)
		{
			ra_rb(&stack->stack_a, OK, 'a');
			num--;
		}
		else
		{
			rra_rrb(&stack->stack_a, OK, 'a');
			num++;
			if (num == stack->stack_a.sizeadd)
				break ;
		}
	}
}

void	rest_number(t_stack *stack, int size)
{
	if (!check_sort(&stack->stack_a))
	{
		while (stack->stack_a.sizeadd >= 5)
		{
			find_small_five(stack);
			pb(&stack->stack_b, &stack->stack_a, OK);
		}
		push_five_number(stack);
		while (stack->stack_a.sizeadd != size)
			pa(&stack->stack_b, &stack->stack_a, OK);
	}
}
