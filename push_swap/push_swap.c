/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:36:26 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 16:49:20 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_num(t_num *stack_a)
{
	int	i;
	int	num;

	i = 0;
	num = i;
	while (i < stack_a->sizeadd)
	{
		if (stack_a->array[num] > stack_a->array[i])
			num = i;
		i++;
	}
	return (num);
}

char	*arg_to_string(char *av)
{
	char	*str;
	int		i;

	i = 1;
	while (av[i])
		i++;
	str = malloc(i * sizeof(char) + 1);
	i = 1;
	while (av[i])
	{
		str[i] = av[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_stack	create_stack(char *tab)
{
	char		**numbers;
	t_stack		stack;
	long long	number;
	int			i;

	i = 0;
	numbers = split_string(tab, &stack);
	while (numbers[i])
	{
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			check_free(&stack, "ERROR");
		if (ft_check_duplicates(&stack, number) == 0)
			check_free(&stack, "ERROR");
		stack.stack_a.array[i] = number;
		stack.stack_a.sizeadd++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stack);
}

void	push_five_hundred(t_stack *stack)
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
	push_one_hundred(stack);
	while (stack->stack_b.sizeadd != 0)
	{
		find_bigg_num(stack);
		pa(&stack->stack_b, &stack->stack_a, OK);
	}
}

int	main(int ac, char **av)
{
	char	*tab;
	t_stack	stack;

	ac--;
	if (ac != 0)
	{
		tab = ft_get_line(av);
		stack = create_stack(tab);
		if (check_sort(&stack.stack_a))
			check_free(&stack, NULL);
		if (stack.stack_a.size == 2)
			sa_sb(&stack.stack_a, OK, 'a');
		else if (stack.stack_a.size == 3)
			three_number(&stack.stack_a);
		else if (stack.stack_a.size == 5 || stack.stack_a.size == 4)
			push_five_number(&stack);
		else if (stack.stack_a.size > 5 && stack.stack_a.size <= 10)
			push_ten_number(&stack);
		else if (stack.stack_a.size > 10 && stack.stack_a.size <= 100)
			push_one_hundred(&stack);
		else if (stack.stack_a.size > 100)
			push_larger_one_handred(&stack);
		check_free(&stack, NULL);
	}
	return (0);
}
