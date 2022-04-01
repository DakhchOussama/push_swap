/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:47:03 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 16:48:19 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_num *stack_b, t_num *stack_a, int type)
{
	int	length_a;
	int	length_b;

	length_a = stack_a->sizeadd;
	length_b = stack_b->sizeadd;
	if (length_a == 0)
		return ;
	if (type)
		write(1, "pb\n", 3);
	if (length_b == 0)
		stack_b->array[0] = stack_a->array[0];
	else
	{
		clear_first_element(stack_b->array, length_b);
		stack_b->array[0] = stack_a->array[0];
	}
	remove_first_element(stack_a->array, length_a);
	stack_b->sizeadd++;
	stack_a->sizeadd--;
}

void	sa_and_sb(t_stack *stack, int type)
{
	if (type)
		write(1, "ss\n", 3);
	sa_sb(&stack->stack_a, type, 'a');
	sa_sb(&stack->stack_b, type, 'b');
}

void	pa(t_num *stack_b, t_num *stack_a, int type)
{
	int	length_a;
	int	length_b;

	length_a = stack_a->sizeadd;
	length_b = stack_b->sizeadd;
	if (length_b == 0)
		return ;
	if (type)
		write(1, "pa\n", 3);
	if (length_a == 0)
		stack_a->array[0] = stack_b->array[0];
	else
	{
		clear_first_element(stack_a->array, length_a);
		stack_a->array[0] = stack_b->array[0];
	}
	remove_first_element(stack_b->array, length_b);
	stack_a->sizeadd++;
	stack_b->sizeadd--;
}

void	arrange_num(t_stack	*stack)
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
	if (stack->stack_a.sizeadd > 5)
		rest_number(stack, stack->stack_a.sizeadd);
}
