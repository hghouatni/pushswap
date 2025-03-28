/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:49:42 by hghoutan          #+#    #+#             */
/*   Updated: 2025/03/28 13:57:47 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && a > c)
		rra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
}

int	find_index(int nb, t_stack *stack)
{
	t_node	*current;
	int		index;

	index = 0;
	current = stack->head;
	while (current)
	{
		if (current->data == nb)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->head;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

void	move_to_top(t_stack *stack_a, int index, int arg_num)
{
	if (index <= arg_num / 2)
	{
		while (index-- > 0)
			ra(stack_a);
	}
	else
	{
		index = arg_num - index;
		while (index-- > 0)
			rra(stack_a);
	}
}

void	small_sort(t_stack *stack_a, t_stack *stack_b, int arg_num)
{
	int	index;

	index = 0;
	if (is_sorted(stack_a) || arg_num == 1)
		return ;
	if (arg_num == 2)
		sa(stack_a);
	else
	{
		while (arg_num > 3)
		{
			index = find_index(find_min(stack_a), stack_a);
			move_to_top(stack_a, index, arg_num);
			pb(stack_a, stack_b);
			arg_num--;
		}
		ft_sort_three(stack_a);
		while (stack_b->head != NULL)
			pa(stack_b, stack_a);
	}
}
