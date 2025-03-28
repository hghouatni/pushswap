/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:11:44 by macbook           #+#    #+#             */
/*   Updated: 2025/03/28 16:51:18 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}
