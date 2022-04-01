/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:59:37 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/27 23:03:52 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_num(int *a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	push_index(t_stack *stack, int num)
{
	int	small_num;

	small_num = search_small(stack, num);
	while (small_num != -1)
	{
		move_top(stack, small_num);
		pb(&stack->stack_b, &stack->stack_a, OK);
		small_num = search_small(stack, num);
	}
}

int	*push_list(t_stack	*stack)
{
	int	i;
	int	*sort_list;

	i = 0;
	sort_list = malloc(sizeof(int) * stack->stack_a.size);
	while (i < stack->stack_a.size)
	{
		sort_list[i] = stack->stack_a.array[i];
		i++;
	}
	return (sort_list);
}

int	*get_list(t_stack *stack)
{
	int	i;
	int	j;
	int	small_num;
	int	*list;

	i = 0;
	list = push_list(stack);
	while (i < stack->stack_a.size - 1)
	{
		small_num = i;
		j = i + 1;
		while (j < stack->stack_a.size)
		{
			if (list[j] < list[small_num])
				small_num = j;
			j++;
		}
		swap_num(&list[small_num], &list[i]);
		i++;
	}
	return (list);
}
