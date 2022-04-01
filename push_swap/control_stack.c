/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:21:29 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 15:55:11 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_number(t_num	*stack)
{
	if ((check_sort(stack)))
		return ;
	if (stack->array[0] > stack->array[1])
		sa_sb(stack, OK, 'a');
	if (!(check_sort(stack)))
		rra_rrb(stack, OK, 'a');
	if (stack->array[0] > stack->array[1])
		sa_sb(stack, OK, 'a');
}

void	push_five_number(t_stack	*stack)
{
	int	i;

	i = 0;
	if (!check_sort(&stack->stack_a))
	{
		if (stack->stack_a.sizeadd == 5)
		{
			find_small(stack);
			pb(&stack->stack_b, &stack->stack_a, OK);
			i++;
		}
		if (stack->stack_a.sizeadd == 4)
		{
			find_small(stack);
			pb(&stack->stack_b, &stack->stack_a, OK);
			i++;
		}
		three_number(&stack->stack_a);
		while (i > 0)
		{
			pa(&stack->stack_b, &stack->stack_a, OK);
			i--;
		}
	}
}

void	find_small_five(t_stack	*stack)
{
	int	num;

	num = small_num(&stack->stack_a);
	while (num != 0)
	{
		if (num <= 5)
			ra_rb(&stack->stack_a, OK, 'a');
		else
			rra_rrb(&stack->stack_a, OK, 'a');
		num = small_num(&stack->stack_a);
	}
}

void	push_ten_number(t_stack	*stack)
{
	if (!check_sort(&stack->stack_a))
	{
		while (stack->stack_a.sizeadd != 5)
		{
			find_small_five(stack);
			pb(&stack->stack_b, &stack->stack_a, OK);
		}
		push_five_number(stack);
		while (stack->stack_a.sizeadd != stack->stack_a.size)
			pa(&stack->stack_b, &stack->stack_a, OK);
	}
}

void	push_one_hundred(t_stack	*stack)
{
	int	*list;
	int	i;
	int	num;

	i = 1;
	list = get_list(stack);
	while (i != 4)
	{
		num = find_number(list, stack->stack_a.size, i, 4);
		push_index(stack, num);
		i++;
	}
	free(list);
	arrange_num(stack);
	while (stack->stack_b.sizeadd != 0)
	{
		find_bigg_num(stack);
		pa(&stack->stack_b, &stack->stack_a, OK);
	}
}
