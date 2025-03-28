/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:30:21 by macbook           #+#    #+#             */
/*   Updated: 2025/03/28 16:48:46 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	stack->head = NULL;
}

void exit_error() {
  write(1, "Error\n", 6);
  exit(1);
}

void init_stack(t_stack *stack)
{
  stack->head = NULL;
}

int	main(int argc, char **argv)
{
	int		size;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	init_stack(&stack_a);
  init_stack(&stack_b);
	if (validate_input(argv, &stack_a))
	{  
		if (is_sorted(&stack_a))
      return (0);
    size = get_size(&stack_a);
		if (size < 20)
			small_sort(&stack_a, &stack_b, size);
		else
			radix_sort(&stack_a, &stack_b, size);
	}
	else 
    exit_error();
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
