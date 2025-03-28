/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:46:08 by hghoutan          #+#    #+#             */
/*   Updated: 2025/03/28 16:03:49 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_convert(t_stack *stack, int *original_values, int *sorted_values,
		int size)
{
	t_node	*current;
	int		i;
	int		j;

	current = stack->head;
	i = 0;
	while (current)
	{
		j = 0;
		while (j < size)
		{
			if (original_values[i] == sorted_values[j])
			{
				current->data = j;
				break ;
			}
			j++;
		}
		current = current->next;
		i++;
	}
}

void	convert_to_indices(t_stack *stack)
{
	int	*sorted_values;
	int	*original_values;
	int	size;

	size = get_size(stack);
	original_values = ft_copy(stack, size);
	sorted_values = ft_copy_and_sort(stack, size);
	ft_convert(stack, original_values, sorted_values, size);
	free(original_values);
	free(sorted_values);
}

int	get_max_bits(t_stack *stack)
{
	int		max_num;
	int		max_bits;
	t_node	*current;

	max_num = 0;
	current = stack->head;
	while (current)
	{
		if (current->data > max_num)
		{
			max_num = current->data;
		}
		current = current->next;
	}
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
	{
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	bit;
	int	max_bits;
	int	moves;
	int	num;

	convert_to_indices(stack_a);
	max_bits = get_max_bits(stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		moves = 0;
		while (moves < size)
		{
			num = stack_a->head->data;
			if (((num >> bit) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			moves++;
		}
		while (stack_b->head)
			pa(stack_b, stack_a);
		bit++;
	}
}
