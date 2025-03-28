/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:22:33 by macbook           #+#    #+#             */
/*   Updated: 2025/03/28 16:51:06 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
	return ;
}
