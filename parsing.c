/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:00:26 by hghoutan          #+#    #+#             */
/*   Updated: 2025/03/27 16:26:14 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack, int data)
{
	t_node	*node;
	t_node	*current;

	node = createt_node(data);
	if (node == NULL)
		return ;
	if (stack->head == NULL)
	{
		stack->head = node;
		return ;
	}
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = node;
}

int	is_valid_number(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

int	validate_and_parse_args(char *arg, t_stack *stack)
{
	char	**split_args;
	int		k;
	long	num;

	split_args = ft_split(arg, ' ');
	k = 0;
	while (split_args[k])
	{
		if (!is_valid_number(split_args[k]))
		{
			free_all(split_args);
			return (0);
		}
		num = ft_atoi(split_args[k]);
		if (num > 2147483647 || num < -2147483648 || ft_exist(stack, num))
		{
			free_all(split_args);
			return (0);
		}
		k++;
	}
	free_all(split_args);
	return (1);
}

int	validate_input(char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!validate_and_parse_args(argv[i], stack))
			return (0);
		i++;
	}
	return (1);
}
