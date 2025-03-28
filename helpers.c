/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:47:53 by hghoutan          #+#    #+#             */
/*   Updated: 2025/03/28 00:00:59 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_copy(t_stack *stack, int size)
{
	t_node	*current;
	int		*copied_values;
	int		i;

	i = 0;
	current = stack->head;
	copied_values = malloc(size * sizeof(int));
	while (current)
	{
		copied_values[i++] = current->data;
		current = current->next;
	}
	return (copied_values);
}

int	*ft_copy_and_sort(t_stack *stack, int size)
{
	int	*sorted_values;
	int	temp;
	int	i;
	int	j;

	sorted_values = ft_copy(stack, size);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted_values[j] > sorted_values[j + 1])
			{
				temp = sorted_values[j];
				sorted_values[j] = sorted_values[j + 1];
				sorted_values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted_values);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->head == NULL)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->data > (current->next->data))
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_size(t_stack *stack)
{
	t_node	*current;
	int		size;

	size = 0;
	current = stack->head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
