/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:27:17 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 15:28:40 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_first_element(int *array, int size)
{
	while (size > 0)
	{
		array[size] = array[size - 1];
		size--;
	}
}

void	remove_first_element(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = array[i + 1];
		i++;
	}
}
