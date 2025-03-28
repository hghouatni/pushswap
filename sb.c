/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:11:44 by macbook           #+#    #+#             */
/*   Updated: 2025/03/28 16:51:22 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}
