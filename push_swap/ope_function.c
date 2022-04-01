/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:14:48 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 16:48:46 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_num	*stack, int type, char c)
{
	int	tmp;

	if (type && c == 'a')
		write(1, "sa\n", 3);
	else if (type && c == 'b')
		write(1, "sa\n", 3);
	if (stack->sizeadd > 1)
	{
		tmp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = tmp;
	}
}

void	rra_rrb(t_num *stack, int type, char c)
{
	int	tmp;

	if (type && c == 'a')
		write(1, "rra\n", 4);
	else if (type && c == 'b')
		write(1, "rrb\n", 4);
	tmp = stack->array[stack->sizeadd - 1];
	clear_first_element(stack->array, stack->sizeadd);
	stack->array[0] = tmp;
}

void	rra_and_rrb(t_stack *stack, int type)
{
	if (type)
		write(1, "rrr\n", 4);
	rra_rrb(&stack->stack_a, type, 'a');
	rra_rrb(&stack->stack_b, type, 'b');
}

void	ra_and_rb(t_stack *stack, int type)
{
	if (type)
		write(1, "rr\n", 4);
	ra_rb(&stack->stack_a, type, 'a');
	ra_rb(&stack->stack_b, type, 'b');
}

void	ra_rb(t_num *stack, int type, char c)
{
	int	tmp;
	int	size;

	size = stack->sizeadd;
	if (type && c == 'a')
		write(1, "ra\n", 3);
	else if (type && c == 'b')
		write(1, "rb\n", 3);
	tmp = stack->array[0];
	remove_first_element(stack->array, stack->sizeadd);
	stack->array[size - 1] = tmp;
}
