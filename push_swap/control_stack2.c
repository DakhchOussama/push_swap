/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_stack2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:31:48 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 15:55:49 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_num	*array)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = array->array;
	while (i < array->sizeadd - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	arrange_num_more_handred(t_stack	*stack)
{
	if (stack->stack_a.sizeadd == 2)
	{
		if (!check_sort(&stack->stack_a))
			sa_sb(&stack->stack_a, OK, 'a');
	}
	if (stack->stack_a.sizeadd == 3)
		three_number(&stack->stack_a);
	if (stack->stack_a.sizeadd == 5 || stack->stack_a.sizeadd == 4)
		push_five_number(stack);
	if (stack->stack_a.sizeadd > 10)
		push_one_hundred(stack);
}

void	push_larger_one_handred(t_stack	*stack)
{
	int	*list;
	int	i;
	int	num;

	i = 1;
	list = get_list(stack);
	while (i != 8)
	{
		num = find_number(list, stack->stack_a.size, i, 8);
		push_index(stack, num);
		i++;
	}
	free(list);
	arrange_num_more_handred(stack);
	while (stack->stack_b.sizeadd != 0)
	{
		find_bigg_num(stack);
		pa(&stack->stack_b, &stack->stack_a, OK);
	}
}

char	**split_string(char *string, t_stack *stack)
{
	long long	num;
	char		**numbers;

	num = count_words(string, ' ');
	numbers = ft_split(string, ' ');
	stack->stack_a.array = malloc(num * sizeof(int));
	stack->stack_b.array = malloc(num * sizeof(int));
	stack->stack_a.size = num;
	stack->stack_b.size = num;
	stack->stack_a.sizeadd = 0;
	stack->stack_b.sizeadd = 0;
	free(string);
	return (numbers);
}
