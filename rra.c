/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:53:45 by macbook           #+#    #+#             */
/*   Updated: 2025/03/28 16:51:09 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	ft_rrotate(stack_a);
	write(1, "rra\n", 4);
}
