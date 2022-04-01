/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:11:23 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/27 20:21:19 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_num(t_num	*stack_a)
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

t_stack	create_stack(char	*tab)
{
	char		**numbers;
	long long	number;
	t_stack		stack;
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

int	check_line(char	*line, t_stack	*stack)
{
	if (!ft_strcmp(line, "ra\n"))
		ra_rb(&stack->stack_a, KO, 'a');
	else if (!ft_strcmp(line, "rb\n"))
		ra_rb(&stack->stack_b, KO, 'b');
	else if (!ft_strcmp(line, "rr\n"))
		ra_and_rb(stack, KO);
	else if (!ft_strcmp(line, "sa\n"))
		sa_sb(&stack->stack_a, KO, 'a');
	else if (!ft_strcmp(line, "sb\n"))
		sa_sb(&stack->stack_b, KO, 'b');
	else if (!ft_strcmp(line, "ss\n"))
		sa_and_sb(stack, KO);
	else if (!ft_strcmp(line, "pa\n"))
		pa(&stack->stack_b, &stack->stack_a, KO);
	else if (!ft_strcmp(line, "pb\n"))
		pb(&stack->stack_b, &stack->stack_a, KO);
	else if (!ft_strcmp(line, "rra\n"))
		rra_rrb(&stack->stack_a, KO, 'a');
	else if (!ft_strcmp(line, "rrb\n"))
		rra_rrb(&stack->stack_b, KO, 'a');
	else if (!ft_strcmp(line, "rrr\n"))
		rra_and_rrb(stack, KO);
	else
		check_free(stack, "error");
	return (1);
}

int	main(int ac, char **av)
{
	char	*tab;
	t_stack	stack;
	char	*line;

	ac--;
	if (ac == 0)
		return (0);
	tab = ft_get_line(av);
	stack = create_stack(tab);
	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		check_line(line, &stack);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (check_sort(&stack.stack_a) && !stack.stack_b.sizeadd)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	check_free(&stack, NULL);
	return (0);
}
